package question32;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class client {
	public static void main(String[] args) {
		try {
	        Socket socket = new Socket("localhost", 9999);
	        BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
	        BufferedReader serverInput = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	        PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
	        System.out.println("Enter a number:");
	        String number = userInput.readLine();
	        writer.println(number);
	        String result = serverInput.readLine();
	        System.out.println("Server Response: " + result);
	        socket.close();
	        userInput.close();
	        serverInput.close();
	        writer.close();
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	}

}
