import java.util.Scanner;

class occurence {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter size");
        int size=sc.nextInt();
        int [] array=new int[size];
        for(int i=0;i<size;i++)
        {
            System.out.println("enter number: ");
            array[i]=sc.nextInt();
        }
        System.out.println("enter number whose occurence you want to check");
        int check=sc.nextInt();
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(check==array[i])
                count++;
        }
        System.out.println("number of occurences- "+count);
        sc.close();
    }
}
