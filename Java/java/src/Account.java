import java.util.*;

class Account
{
	String name;
	int AcNumber;
	float Balance;
	Account(String name,int AcNumber,float Balance)
	{
		this.name = name;
		this.AcNumber=AcNumber;
		this.Balance=Balance;
	}
	void withdraw(int withdrawAmt)
	{
		Balance-=withdrawAmt;
	}
	void deposit(int depositAmt)
	{
		Balance+=depositAmt;
	}
	void balanceInquiry()
	{
		System.out.println("Balance: "+Balance);
	}
	void display()
	{
		System.out.println("Name: "+name+"Balance: "+Balance);
	}
}

class SavingsAccount extends Account
{
	float interestRate;
	SavingsAccount(String name,int AcNumber,float Balance,float interestRate)
	{
		super(name,AcNumber,Balance);
		this.interestRate=interestRate;
	}
	float calculateInterest()
	{
		float x;
		x=Balance*interestRate/100;
		return x;
	}
}

class CurrentAccount extends Account
{
	double fee;
	CurrentAccount(String name,int AcNumber,float Balance,double fee)
	{	
		super(name,AcNumber,Balance);
		this.fee=fee;
	}
	void withdraw(float withdrawAmt)
	{
		Balance-=withdrawAmt-fee;
	}
	void deposit(float depositAmt)
	{
		Balance+=depositAmt-fee;
	}
}

class AccountMain
{
	public static void main(String[] a)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter account holder name");
		String name=sc.nextLine();
		System.out.println("enter account number");
		int num=sc.nextInt();
		System.out.println("enter account balance");
		float bal=sc.nextFloat();
		System.out.println("enter interestRate");
		float rate=sc.nextFloat();
		System.out.println("enter fee");
		double fee=sc.nextDouble();
		CurrentAccount ca=new CurrentAccount(name,num,bal,fee);
		System.out.println("enter depositAmt");
		float dep=sc.nextFloat();
		ca.deposit(dep);
		ca.balanceInquiry();
		System.out.println("enter withdrawAmt");
		float with=sc.nextFloat();
		ca.withdraw(with);
		ca.balanceInquiry();
	}
}