// sum of first 999 numbers using threads.
class sumofarray extends Thread
{
    int sum;
    int low;
    int high;
    String name;
    sumofarray(int low,int high,String name)
    {
        this.low = low;
        this.high = high;
        this.name = name;
        sum=0;
        start();
    }
    public void run()
    {
        System.out.println(name+" starts...");
        for(int i=low;i<high;i++)
            sum+=i;
    }
    int getsum()
    {
        return sum;
    }
}

class sumofarrayMain extends Exception
{
    public static void main(String[] args) {
        sumofarray t1=new sumofarray(0, 500, "thread-1");
        sumofarray t2=new sumofarray(500, 1000, "thread-2");
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        System.out.println("SUM-> "+(t1.getsum()+t2.getsum()));
    }
}