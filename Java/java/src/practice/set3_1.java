package practice;
import java.util.Scanner;

class InvalidMarksException extends Exception{
    public String toString(){
        return "Invalid Marks Exception";
    }
}
class FailedException extends Exception{
    public String toString(){
        return "Failed Exception";
    }
}

class Student {
    int reg,crs,in_marks,end_marks;
    String name;
    Student(int reg,String name,int crs,int in_marks,int end_marks){
        this.reg = reg;
        this.crs = crs;
        this.in_marks = in_marks;
        this.name = name;
        this.end_marks = end_marks;
    }
    void isPassFail(){
        double total;
        double end = end_marks*0.4;
        total = in_marks+end;
        try{
            if(end_marks<40 || total<46)
                throw new FailedException();
            else
                System.out.println("Student Passed");
        }
        catch(FailedException e){
            System.out.println(e);
        }
    }
}

public class set3_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int reg,crs,in_marks,end_marks;
        String name;
        System.out.println("enter register number: ");
        reg = sc.nextInt();
        System.out.println("enter name: ");
        name = sc.next();
        System.out.println("enter course code: ");
        crs = sc.nextInt();
        System.out.println("enter internal marks: ");
        in_marks = sc.nextInt();
        System.out.println("enter end term marks: ");
        end_marks = sc.nextInt();
        try{
            if(end_marks>100)
                throw new InvalidMarksException();
        }
        catch(InvalidMarksException e){
            System.out.println(e);
            System.out.println("enter end term marks: ");
            end_marks = sc.nextInt();
        }
        Student s1 = new Student(reg,name,crs,in_marks,end_marks);
        s1.isPassFail();
    }
}
