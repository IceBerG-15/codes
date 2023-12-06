package practice;
import java.util.Random;

class threads extends Thread{
    int low, high;
    int[] a;
    int nums;
    threads(int[] a,int low,int high){
        this.low = low;
        this.high = high;
        this.a = a;
        start();
    }
    public void run(){
        int i;
        nums=0;
        for(i=low;i<=high;i++){
            if(a[i]>60)
                nums++;
        }
    }
}

class set1_1{
    public static void main(String[] args){
        int[] a = new int[2000];
        Random r = new Random();
        int i;
        for(i=0;i<a.length;i++)
            a[i] = r.nextInt(80);
        threads t1 = new threads(a,0,1000);
        threads t2 = new threads(a,1001,1999);
        try{
            t1.join();
            t2.join();
        }
        catch(Exception e){
            System.out.println(e);
        }
        int nums = t1.nums+t2.nums;
        System.out.println("Number of old peoples are: "+nums);
    }
}