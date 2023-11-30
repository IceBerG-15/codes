package question33;

import java.rmi.*;
import java.rmi.server.UnicastRemoteObject;

public class StringSearchImpl extends UnicastRemoteObject implements StringSearchInterface {
    protected StringSearchImpl() throws RemoteException {
        super();
    }

    @Override
    public boolean searchSubstring(String mainString, String substring) throws RemoteException {
        return mainString.contains(substring);
    }
}