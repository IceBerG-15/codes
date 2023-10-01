//question-8

import java.util.*;

class GameCharge
{
	String name;
	int GameType;
	char PersonType;
	int Amount;
	
	GameCharge()
	{
		name="\0";
		GameType=0;
		PersonType='\0';
		Amount=0;
	}
	
	void getData()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter person details:");
		System.out.println("Enter person name:");
		name=sc.nextLine();
		System.out.println("Enter game type:\n 1-Gymnasium & Snooker\n 2-Indoor Badminton\n 3-Squash\n 4-Synthetic Tennis  ");
		GameType=sc.nextInt();
		System.out.println("Enter person type:\n S-Student\n F-Faculty  ");
		PersonType=sc.next().charAt(0);
	}
	
	static void dispAmount(GameCharge[] Game,int size)
	{
		int i;
		for(i=0;i<size;i++)
		{
			switch(Game[i].GameType)
			{
				case 1:
					if(Game[i].PersonType=='S' || Game[i].PersonType=='s' )
						Game[i].Amount=2500;
					else
						Game[i].Amount=1750;
					break;
				case 2:
					if(Game[i].PersonType=='S' || Game[i].PersonType=='s' )
						Game[i].Amount=1000;
					else
						Game[i].Amount=750;
					break;
				case 3:
					if(Game[i].PersonType=='S' || Game[i].PersonType=='s' )
						Game[i].Amount=1000;
					else
						Game[i].Amount=750;
					break;
				case 4:
					if(Game[i].PersonType=='S' || Game[i].PersonType=='s' )
						Game[i].Amount=2000;
					else
						Game[i].Amount=1500;
					break;
				default:
					System.out.println("Error");
					break;
			}
			System.out.println(" name: "+Game[i].name+"\n Amount: "+Game[i].Amount);
		}
	}
	
	public static void main(String[] a)
	{
		Scanner sc=new Scanner(System.in);
		int size;
		System.out.println("enter size: ");
		size=sc.nextInt();
		int i;
		GameCharge[] Game= new GameCharge[size];
		for(i=0;i<size;i++)
		{
			Game[i]=new GameCharge();
			Game[i].getData();
			
		}
		dispAmount(Game,size);
		
	}
}