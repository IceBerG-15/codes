//question-6

import java.util.*;

class Overload
{
	public static void main(String[] a)
	{
		int size,i;
		Scanner sc=new Scanner(System.in);
		int ch;
		System.out.println("MENU");
		System.out.println("1-int   2-float 3-exit");
		System.out.println("enter choice: ");
		ch=sc.nextInt();
		switch(ch)
		{
			case 1:
				System.out.println("enter size: ");
				size=sc.nextInt();
				int[] array=new int[size];
				for(i=0;i<size;i++)
				{
					System.out.println("enter number: ");
					array[i]=sc.nextInt();
				}
				int p=productOfNumber(array,size);
				System.out.println("product: "+p);
				break;
			case 2:
				System.out.println("enter size: ");
				size=sc.nextInt();
				float[] arr=new float[size];
				for(i=0;i<size;i++)
				{
					System.out.println("enter number: ");
					arr[i]=sc.nextFloat();
				}
				float pro=productOfNumber(arr,size);
				System.out.println("product: "+pro);
				break;
			case 3:
				System.out.println("exitted successfully");
				break;
			default:
				System.out.println("enter valid option ");
				break;
		}
	}
	
	static int productOfNumber(int[] array,int size)
	{
		int i,prod=1;
		for(i=0;i<size;i++)
			prod*=array[i];
		return prod;
	}
	
	static float productOfNumber(float[] array,int size)
	{
		int i;
		float pro=1.0f;
		for(i=0;i<size;i++)
			pro*=array[i];
		return pro;
	}
	
}