import package2.*;
import java.util.Scanner;

public class question13 {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        String FacultyID;
        String Name;
        int no_of_pub;
        int no_of_cit;
        System.out.println("enter Faculty ID: ");
        FacultyID=sc.next();
        System.out.println("enter Name: ");
        Name=sc.next();
        System.out.println("enter number of publications: ");
        no_of_pub=sc.nextInt();
        System.out.println("enter number of citations: ");
        no_of_cit=sc.nextInt();
        FacultyPublicationPoint f=new FacultyPublicationPoint(FacultyID, Name, no_of_pub, no_of_cit);
        f.display();
        System.out.println("Points-> "+f.determinePoints());
        sc.close();
    }
}