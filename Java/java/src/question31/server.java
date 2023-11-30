package question31;

import java.io.*;
import java.net.*;

public class server {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(9999);
            System.out.println("Server waiting for connections...");

            Socket socket = serverSocket.accept();
            System.out.println("Connection established with " + socket.getInetAddress().getHostName());

            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

            String receivedMessage = reader.readLine();
            System.out.println("Client: " + receivedMessage);

            // Sending a response back to the client
            writer.println("Message received by server");

            // Closing resources
            writer.close();
            reader.close();
            socket.close();
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}