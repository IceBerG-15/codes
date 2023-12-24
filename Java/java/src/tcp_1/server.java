package tcp_1;

import java.net.*;
import java.io.*;

public class server{
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(4001);
        System.out.println("server waiting...");
        Socket socket = server.accept();
        System.out.println("connection done...");
        BufferedReader buff = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter pw = new PrintWriter(socket.getOutputStream());
        String line = buff.readLine();
        System.out.println(line);
        pw.println("message received");
        
        pw.close();
        buff.close();
        socket.close();
        server.close();
    }
}