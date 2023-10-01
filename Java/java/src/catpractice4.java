
import java.util.Scanner;

class InvalidYearException extends Exception
{
    public String toString()
    {
        return "\nInvalid Year of Graduation.. ";
    }
}
class InvalidAmountException extends Exception
{
    public String toString()
    {
        return "\nInvalid Donation Amount.. ";
    }
}
class Alumni
{
    String name;
    int year;
    float amount;
    Alumni(String name, int year, float amount)
    {
        this.name = name;
        this.year=year;
        this.amount = amount;
    }
    void display()
    {
        System.out.println("\nAlumni name-> "+name);
        System.out.println("Alumni year of graduation-> "+year);
        System.out.println("Alumni donated this amount-> "+amount);
    }
}


class catpractice4 {
    public static void main(String[] args) 
    {
        String name;
        int year;
        float amount;
        Scanner sc=new Scanner(System.in);
        System.out.println("Alumni name-> ");
        name=sc.next();
        System.out.println("Alumni year of graduation-> ");
        year=sc.nextInt();
        System.out.println("Alumni donated this amount-> ");
        amount=sc.nextFloat();
        try
        {
            if(year<1988 || year>2023)
                throw new InvalidYearException();
            else if(amount<0)
                throw new InvalidAmountException();
        }
        catch(InvalidAmountException e)
        {
            System.out.println(e);
        }
        catch(InvalidYearException e)
        {
            System.out.println(e);
        }
        Alumni a=new Alumni(name, year, amount);
        a.display();
    }    
}
