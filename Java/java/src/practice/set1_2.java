package practice;
import java.util.Scanner;

import practice.package1.straightline;

public class set1_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x1,y1,x2,y2;
        double slope;
        System.out.println("enter x1: ");
        x1 = sc.nextInt();
        System.out.println("enter y1: ");
        y1 = sc.nextInt();
        System.out.println("enter x2: ");
        x2 = sc.nextInt();
        System.out.println("enter y2: ");
        y2 = sc.nextInt();
        straightline s1 = new straightline(x1,y1,x2,y2);
        slope = s1.find_slope();
        System.out.println("slope: "+slope);
    }
}
