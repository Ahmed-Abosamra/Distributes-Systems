import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.RemoteException;

public class HelloServer {
    public static void main(String[] args) {
        String serviceName = "HelloService";

        try {
            HelloServant helloObj = new HelloServant();
            Registry registry = LocateRegistry.createRegistry(HelloI.port);
            registry.rebind(serviceName, helloObj);
            System.out.println("Server is running...");
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
