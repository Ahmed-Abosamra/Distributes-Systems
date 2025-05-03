import java.io.Serializable;
import java.util.Arrays;

public class Result implements Serializable {
    int min_num;
    int[] digits_array;

    public Result(int min, int[] digits) {
        this.min_num = min;
        this.digits_array = digits;
    }

    @Override
    public String toString() {
        return "Minimum coins: " + min_num + "\nunique_digits: " + Arrays.toString(digits_array);
    }
}
