//question15 using runnable imterface
import java.util.Random;

class thread1 implements Runnable
{
    int low,high,max;
    int[] a;
    thread1(int[] a,int low,int high)
    {
        this.low = low;
        this.high = high;
        this.a = a;
        max=a[low];
    }
    void findMax()
    {
        int i;
        for(i=low+1;i<=high;i++)
        {
            if(max<a[i])
                max=a[i];
        }
    }
    public void run()
    {
        findMax();
    }
}

class Q15 
{
    public static void main(String[] args) 
    {
        Random r = new Random();
        int[] array=new int[1000];
        int i;
        for(i=0;i<array.length;i++)
            array[i]=r.nextInt(2000);
        thread1 tt1 = new thread1(array, 0, 499);
        Thread t1 = new Thread(tt1);
        thread1 tt2 = new thread1(array, 500, 999);
        Thread t2 = new Thread(tt2);
        t1.start();
        t2.start();
        try{
            t1.join();
            t2.join();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        if(tt1.max>tt2.max)
            System.out.println("max: "+tt1.max);
        else    
            System.out.println("max: "+tt2.max);
    }
}
