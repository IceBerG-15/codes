//Write a Java program that creates two threads to find and print even and odd numbers from 1 to 20.
class threads extends Thread
{
    public static int MAX=20;
    String name;
    threads(String name)
    {
        this.name = name;
        start();
    }
    int isEven(int n)
    {
        if(n%2==0)
            return 1;
        return 0;
    }
    void even()
    {
        for(int i=1; i<=MAX; i++)
            if(isEven(i)==1)
                System.out.println("EVEN: " + i);
    }
    void odd()
    {
        for(int i=1; i<MAX; i++)
            if(isEven(i)==0)
                System.out.println("ODD: " + i);
    }
    public void run()
    {
        System.out.println(name + " starts..");
        if(name.equals("even"))
            even();
        else
            odd();
    }
}


class threadspractice1 {
    public static void main(String[] args) {
        threads t1=new threads("odd");
        t1=new threads("even");
    }
}
