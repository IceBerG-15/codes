
import java.util.Scanner;

class invalidDaysException extends Exception 
{
    public String toString()
    {
        return "INVALID DAYS Exception... leave days should be in the range of 0.5 to 5";
    }
}

class ZeroLeaveBalanceException extends Exception
{
    public String toString()
    {
        return "Zero Leave Balance Exception... ";
    }
}

class Employee
{
    String Emp_id;
    String Name;
    int leaveBalance;
    Employee()
    {
        Emp_id=null;
        Name=null;
        leaveBalance=0;
    }
    Employee(String emp_id, String name, int leaveBalance)
    {
        Scanner s=new Scanner(System.in);
        this.Emp_id=emp_id;
        this.Name=name;
        while(leaveBalance>10)
        {
            System.out.println("enter leave balance less than 10 !!");
            System.out.println("enter leave balance: ");
            leaveBalance=s.nextInt();
        }
        this.leaveBalance=leaveBalance;
    }
    void applyLeave(int leave)
    {
        try 
        {
            if(leave<1 || leave>5)
                throw new invalidDaysException();
            else if(leaveBalance==0)
                throw new ZeroLeaveBalanceException();
        } 
        catch (invalidDaysException e) 
        {
            System.out.println(e);
        }
        catch(ZeroLeaveBalanceException d)
        {
            System.out.println(d);
        }
        leaveBalance-=leave;
    }
    void display()
    {
        System.out.println("employee id--> "+Emp_id);
        System.out.println("Name--> "+Name);
        System.out.println("leave balance--> "+leaveBalance);
    }
}


class catpractice2  
{
    public static void main(String[] args) {
        String Emp_id;
        String Name;
        int leaveBalance;
        int leave;
        Scanner sc=new Scanner(System.in);
        System.out.println("enter employee id: ");
        Emp_id=sc.next();
        System.out.println("enter employee name: ");
        Name=sc.next();
        System.out.println("enter employee leave balance: ");
        leaveBalance=sc.nextInt();
        Employee e1=new Employee(Emp_id, Name, leaveBalance);
        System.out.println("enter days of leave u want: ");
        leave=sc.nextInt();
        e1.applyLeave(leave);
        e1.display();
    }
}
