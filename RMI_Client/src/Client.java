import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Registry registry = LocateRegistry.getRegistry("localhost", 2000);
            HelloI stub = (HelloI) registry.lookup("HelloService");

            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter registration number: ");
            String regNum = scanner.nextLine();

            System.out.print("Enter target : ");
            int target = scanner.nextInt();

            Result result = stub.sayHello(regNum, target);

            System.out.println("results:");
            System.out.println(result.toString());

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
