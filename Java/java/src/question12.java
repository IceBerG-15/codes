import java.util.Scanner;
class InvalidMobileNumberException extends Exception
{
    public String toString()
    {
        return "Invalid Mobile Number";
    }
}

class question12 
{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String name;
        int age;
        String mobile;
        System.out.println("enter name: ");
        name=sc.next();
        System.out.println("enter age: ");
        age=sc.nextInt();
        System.out.println("enter mobile number: ");
        mobile=sc.next();
        long mob=0;
        try
        {
            if(mobile.length()!=10)
                throw new InvalidMobileNumberException();
            mob=Long.parseLong(mobile);
        }
        catch(InvalidMobileNumberException e)
        {
            System.out.println(e);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        System.out.println("Name-> "+name+"\nMobile->"+mob +"\nage-> "+age);
    }
}
