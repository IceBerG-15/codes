package tcp_1;

import java.net.*;
import java.io.*;

public class client {
    public static void main(String[] args) throws Exception{
        Socket socket = new Socket("localhost",4001);
        BufferedReader buff = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter pw = new PrintWriter(socket.getOutputStream());
        pw.write("konichawa...");
        String receiveString = buff.readLine();
        System.out.println(receiveString);
        pw.close();
        buff.close();
        socket.close();
    }
}
