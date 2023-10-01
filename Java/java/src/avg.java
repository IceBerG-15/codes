import java.util.Scanner;

class avg {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        double sum=0;
        int[] array=new int[6];
        for(int i=0;i<array.length;i++)
        {
            System.out.println("Enter number:");
            array[i]=sc.nextInt();
            sum+=array[i];
        }
        System.out.println(sum/array.length);
        for(int x:array)
        {
            System.out.print(x+" ");
        }
        sc.close();
    }
}
