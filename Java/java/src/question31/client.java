package question31;

import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("localhost", 9999);

            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);

            // Sending a message to the server
            writer.println("Hello from client");

            // Reading the server's response
            String receivedMessage = reader.readLine();
            System.out.println("Server: " + receivedMessage);

            // Closing resources
            writer.close();
            reader.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}