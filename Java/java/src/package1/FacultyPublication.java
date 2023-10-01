package package1;

public class FacultyPublication {
    String FacultyID;
    String Name;
    int no_of_pub;
    public int no_of_cit;
    public FacultyPublication(String FacultyID,String Name,int no_of_pub,int no_of_cit)
    {
        this.FacultyID = FacultyID;
        this.Name = Name;
        this.no_of_cit = no_of_cit;
        this.no_of_pub=no_of_pub;
    }
    public void display()
    {
        System.out.println("FacultyID-> "+FacultyID+"\nName-> "+Name+"\nnumber of publication-> "+no_of_pub+"\nnumber of citations-> "+no_of_cit);
    }
}
