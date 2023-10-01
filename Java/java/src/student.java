
import java.util.Scanner;

class Student{
    String regNo;       //registration number
    String Name;        //name of student
    float cgpa;         //cgpa of student
    Student(){          //default constructor
        regNo="23MCA0000";
        Name="Student";
        cgpa=9f;
    }
    Student(String regNo, String Name, float cgpa){         //parameterized constructor
        this.regNo=regNo;
        this.Name=Name;
        this.cgpa=cgpa;
    }
    static void display(Student[] stud,int size){       //this method will display students with initial letter as A
        for(int i=0;i<size;i++){
            if(stud[i].Name.charAt(0)=='A' || stud[i].Name.charAt(0)=='a'){  //charAt is used to access the given index char of the string
                System.out.println("Student details are " + stud[i].regNo + " "+stud[i].Name+" "+stud[i].cgpa);
            }
        }
    }
    static void highestCGPA(Student[] stud,int size){   //this method will display students details with highest CGPA
        float max=stud[0].cgpa;
        int a=0;
        for(int i=0;i<size;i++){
            if(stud[i].cgpa>max){
                max=stud[i].cgpa;
                a=i;
            }
        }
        System.out.println("The highest CGPA is " + max + " and student details are " + stud[a].regNo +" " +stud[a].Name+" "+stud[a].cgpa);
    }
    static void above9CGPA(Student[] stud,int size){    //this method will display students details whose CGPA is above 9
        for(Student s:stud){
            if(s.cgpa>=9){
                System.out.println("Student details are " + s.regNo + " "+s.Name+" "+s.cgpa);
            }
        }
    }
    public static void main(String[] args){     //Main method
        Scanner sc=new Scanner(System.in);      //Scanner is called
        System.out.println("enter number of students: ");
        int size=sc.nextInt();                  //size of student array
        String reg,name;
        float c;
        Student[] students=new Student[size];   //initialising student object array
        for(int i=0; i<size; i++){
            System.out.println("Enter details of student "+(i+1));
            System.out.println(" regNo, name, cgpa:");
            reg=sc.next();
            name=sc.next();
            c=sc.nextFloat();
            students[i]=new Student(reg, name, c);
        }
        int ch=1;  //choice variable
        while(ch<4)
        {
            System.out.println("MENU:");
            System.out.println(" 1-display students whose name starts with A \n 2-highest cgpa\n 3-students with above 9 cgpa");
            System.out.println("enter your choice");
            ch=sc.nextInt();
            switch(ch){
                case 1:
                    display(students, size);
                    break;
                case 2:
                    highestCGPA(students, size);
                    break;
                case 3:
                    above9CGPA(students, size);
                    break;
                default:
                    System.out.println("enter valid option");
                    break;
            }
        }
        sc.close();
    }
}
