import java.util.Scanner;

interface Exam
{
    public float Average(int[] a);
}
interface Classify
{
    public String determineClass(float avg);
}
class Result implements Exam, Classify
{
    @Override
    public float Average(int[] a)
    {
        float avg=0;
        for (int i=0; i<a.length; i++)
            avg=avg+a[i];
        avg/=a.length;
        return avg;
    }
    @Override
    public String determineClass(float avg)
    {
        if(avg>=70)
            return "FIRST CLASS WITH DISTINCTION";
        else if(avg<70 && avg>=60)
            return "FIRST CLASS";
        else if(avg<60 && avg>=50)
            return "SECOND CLASS";
        else
            return "NO DIVISION";
    }
}

class question11
{
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("enter n: ");
        int n=sc.nextInt();
        int arsize;
        Result[] s= new Result[n];
        for(int i=0; i<n; i++)
        {
            s[i]=new Result();
            System.out.println("enter arraysize: ");
            arsize=sc.nextInt();
            int[] ar= new int[arsize];
            for(int j=0;j<arsize; j++)
            {
                System.out.println("enter array element: ");
                ar[j]=sc.nextInt();
            }
            System.out.println(s[i].determineClass(s[i].Average(ar)));
        }
        sc.close();
    }
}