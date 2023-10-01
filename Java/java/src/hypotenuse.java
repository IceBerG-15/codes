import java.util.Scanner;

class hypotenuse {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter x");
        double x=sc.nextDouble();
        System.out.println("Enter y");
        double y=sc.nextDouble();
        double z=Math.sqrt(x*x+y*y);
        System.out.println("Hypotenuse of the triangle is "+z);
        sc.close();
    }
}
