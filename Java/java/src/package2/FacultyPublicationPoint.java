package package2;
import package1.*;

interface Calculate
{
    public float determinePoints();
}

public class FacultyPublicationPoint extends FacultyPublication implements Calculate
{
    public FacultyPublicationPoint(String FacultyID,String Name,int no_of_pub,int no_of_cit)
    {
        super(FacultyID,Name,no_of_pub,no_of_cit);
    }
    public float determinePoints()
    {
        float points=10;
        if(no_of_cit<=25)
            points=3;
        else if(no_of_cit>25 && no_of_cit<=50)
            points=5;
        else if(no_of_cit>50 && no_of_cit<=75)
            points=7.5f;
        else if(no_of_cit>75 && no_of_cit<=100)
            points=10;
        else
        {
            int mod;
            mod=(no_of_cit-100)/50;
            if((no_of_cit-100)%50==0)
                points+=(mod*2.5);
        }
        return points;
    }
}

