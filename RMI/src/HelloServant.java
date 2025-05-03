import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class HelloServant extends UnicastRemoteObject implements HelloI {

    private static final long serialVersionUID = 1L;

    protected HelloServant() throws RemoteException {
        super();
    }

    @Override
    public Result sayHello(String regNum, int target) throws RemoteException {
        Set<Integer> uniqueDigits = new HashSet<>();
        for (int i = 0; i < regNum.length(); i++) {
            char c = regNum.charAt(i);
            if (Character.isDigit(c)) {
                uniqueDigits.add(c - '0');
            }
        }

        int[] digits = new int[uniqueDigits.size()];
        int index = 0;
        for (Integer digit : uniqueDigits) {
            digits[index] = digit;
            index++;
        }

        Arrays.sort(digits);

        int maxValue = target + 1;
        int[] dp = new int[target + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i] = maxValue;
        }
        dp[0] = 0;

        for (int i = 1; i <= target; i++) {
            for (int coin : digits) {
                if (coin <= i) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        int minCoins = (dp[target] > target) ? -1 : dp[target];

        return new Result(minCoins, digits);
    }
}
