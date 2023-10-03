import java.util.Scanner;
class producer extends Thread
{
    producer()
    {
        start();
    }
    void getData()
    {
        String s=new String();
        Scanner sc = new Scanner(System.in);
        // System.out.println("enter string: ");
        // s=sc.next();
        while(!s.equals("stop"))
        {
            System.out.println("enter string: ");
            s=sc.next();
        }
    }
    public void run()
    {
    }
}
class consumer extends Thread
{
    consumer()
    {
        start();
    }
    public void run()
    {   
    }
}
class question16 {
}
