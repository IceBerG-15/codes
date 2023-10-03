import java.util.Scanner;
class tribonacci extends Thread
{
    int n;
    int count;
    tribonacci(int n)
    {
        this.n = n;
        count=0;
        start();
    }
    void tribo(int n1,int n2,int n3)
    {
        int sum=n1+n2+n3;
        while(count<n-3)
        {
            System.out.println(sum+" ");
            count++;
            tribo(n2,n3,sum);
        }
    }
    public void run()
    {
        System.out.println("TRIBONACCI -> ");
        System.out.println(0+" ");
        System.out.println(1+" ");
        System.out.println(1+" ");
        tribo(0,1,1);
    }
}

class fibonacci extends Thread
{
    int n;
    int count;
    fibonacci(int n)
    {
        this.n = n;
        count=0;
        start();
    }
    void fibo(int n1,int n2)
    {
        int sum=n1+n2;
        while(count<n-2)
        {
            System.out.println(sum+" ");
            count++;
            fibo(n2,sum);
        }
    }
    public void run()
    {
        System.out.println("FIBONACCI -> ");
        System.out.println(0+" ");
        System.out.println(1+" ");
        fibo(0,1);
    }
}

class question14
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("enter number of elements: ");
        n=sc.nextInt();
        fibonacci f = new fibonacci(n);
        try
        {
            f.join();
        }
        catch(InterruptedException e)
        {
            System.out.println(e);
        }
        tribonacci t = new tribonacci(n);
    }
}