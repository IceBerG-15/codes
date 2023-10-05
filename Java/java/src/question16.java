import java.util.Scanner;

class product
{
    String s;
    boolean valueset = false;
    synchronized void put(String n)
    {
        while(valueset)
        {
            try
            {
                wait();
            }
            catch (Exception e)
            {
                System.out.println(e);
            }
        }
        this.s=n;
        valueset=true;
        System.out.println("put "+s);
        notify();
    }
    synchronized void get()
    {
        while(!valueset)
        {
            try 
            {
                wait();
            } 
            catch (Exception e) 
            {
                System.out.println(e);
            }
        }
        System.out.println("got "+s);
        valueset=false;
        notify();
    }
}

class producer extends Thread
{
    product p;
    producer(product p)
    {
        this.p=p;
        new Thread(this, "Producer").start();
    }
    public void run()
    {
        Scanner sc=new Scanner(System.in);
        String string=new String("new");
        while(!string.equals("stop"))
        {
            System.out.println("enter string (enter 'stop' to stop): ");
            string=sc.next();
            p.put(string);
        }
    }
}

class consumer implements Runnable
{
    product p;
    consumer(product p)
    {
        this.p=p;
        new Thread(this, "Consumer").start();
    }
    public void run()
    {
        p.get();
    }
}
class question16 {
    public static void main(String[] args) {
        product p = new product();
        new producer(p);
        new consumer(p);
    }
}
