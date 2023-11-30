package question33;

import java.rmi.*;

public interface StringSearchInterface extends Remote {
    boolean searchSubstring(String mainString, String substring) throws RemoteException;
}

