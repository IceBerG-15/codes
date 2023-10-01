import java.util.Scanner;

class calculator
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int a;
        int b;
        float result;
        System.out.println("enter operator / * - + % ");
        String op=sc.next();
        switch(op)
        {
            case "/":
                System.out.println("enter number ");
                a=sc.nextInt();
                b=sc.nextInt();
                result = a/b;
                System.out.println("result :"+result);
                break;
            case "*":
                System.out.println("enter number ");
                a=sc.nextInt();
                b=sc.nextInt();
                result = a*b;
                System.out.println("result :"+result);
                break;
            case "+":
                System.out.println("enter number ");
                a=sc.nextInt();
                b=sc.nextInt();
                result = a+b;
                System.out.println("result :"+result);
                break;
            case "-":
                System.out.println("enter number ");
                a=sc.nextInt();
                b=sc.nextInt();
                result = a-b;
                System.out.println("result :"+result);
                break;
            case "%":
                System.out.println("enter number ");
                a=sc.nextInt();
                b=sc.nextInt();
                result = a%b;
                System.out.println("result :"+result);
                break;
            default:
                System.out.println("enter valid operator");
                break;
        }
        sc.close();
    }
}