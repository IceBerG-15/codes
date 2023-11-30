package question33;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;

public class StringSearchServer {
    public static void main(String[] args) {
        try {
            StringSearchInterface searchImpl = new StringSearchImpl();
            
            LocateRegistry.createRegistry(1099);
            Naming.rebind("StringSearchServer", searchImpl);

            System.out.println("Server is running...");
        } catch (RemoteException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
