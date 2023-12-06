package practice;
import java.util.Scanner;

class triangle {
    int a,b,c;
    triangle(int a,int b,int c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
}

interface chktriangle {
    public String isTriangle();
}

class check extends triangle implements chktriangle {

    check(int a,int b,int c){
        super(a,b,c);
    }

    @Override
    public String isTriangle(){
        if(a+b>c || b+c>a || a+c>b){
            if(a==b && b==c)
                return "Equilateral";
            else if(a==b || b==c || a==c)
                return "isosceles";
            else 
                return "Scalene";
        }
        return "Not a";
    }
}
public class set2_1 {
    public static void main(String[] args) {
        int a,b,c;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter a: ");
        a = sc.nextInt();
        System.out.println("enter b: ");
        b = sc.nextInt();
        System.out.println("enter c: ");
        c = sc.nextInt();
        check ch = new check(a, b, c);
        System.out.println("the given is "+ch.isTriangle()+" triangle.");
    }
}
