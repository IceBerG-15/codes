package question33;

import java.rmi.*;
import java.util.Scanner;

public class StringSearchClient {
    public static void main(String[] args) {
        try {
            StringSearchInterface searchInterface = (StringSearchInterface) Naming.lookup("rmi://localhost/StringSearchServer");
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the main string: ");
            String mainString = scanner.nextLine();
            System.out.print("Enter the substring to search: ");
            String substring = scanner.nextLine();           
            boolean found = searchInterface.searchSubstring(mainString, substring);
            if (found) {
                System.out.println("Substring found in the main string.");
            } else {
                System.out.println("Substring not found in the main string.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
