import java.util.Random;

class thread1 extends Thread 
{
    int low,high,max;
    int[] a;
    thread1(int[] a,int low,int high)
    {
        this.low = low;
        this.high = high;
        this.a = a;
        max=a[low];
        start();
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

class thread2 extends Thread 
{
    int low,high,max;
    int[] a;
    thread2(int[] a,int low,int high)
    {
        this.low = low;
        this.high = high;
        this.a = a;
        max=a[low];
        start();
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

class question15 
{
    public static void main(String[] args) 
    {
        Random r = new Random();
        int[] array=new int[1000];
        int i;
        for(i=0;i<array.length;i++)
            array[i]=r.nextInt(2000);
        thread1 t1 = new thread1(array, 0, 500);
        thread2 t2 = new thread2(array,501,999);
        try{
            t1.join();
            t2.join();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        if(t1.max>t2.max)
            System.out.println("max: "+t1.max);
        else    
            System.out.println("max: "+t2.max);
    }
}
