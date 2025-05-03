import java.rmi.Remote;
import java.rmi.RemoteException;

public interface HelloI extends Remote {
    int port = 2000;
    Result sayHello(String regNum , int target) throws RemoteException;
}

