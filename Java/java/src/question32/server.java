package question32;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class server {
	
	private static int calculateProductOfDigits(int number) {
        int product = 1;
        while (number != 0) {
            int digit = number % 10;
            product = product * digit;
            number = number/10;
        }
        return product;
    }
	public static void main(String[] args) {
		try {
            ServerSocket serverSocket = new ServerSocket(9999);
            System.out.println("Server waiting for connections...");
            while (true) {
                Socket socket = serverSocket.accept();
                System.out.println("Connection established with " + socket.getInetAddress().getHostName());
                BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
                String number = reader.readLine();
                int product = calculateProductOfDigits(Integer.parseInt(number));
                writer.println("Product of digits: " + product);
                socket.close();
                reader.close();
                writer.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
	}

}
