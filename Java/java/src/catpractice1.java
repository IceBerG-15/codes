
class catpractice1 {
    public static void main(String[] args) {
        if(args.length<10)
            System.out.println("enter marks of 10 students...  ");
        else
        {
            float[] marks = new float[args.length];
            for(int i=0; i<args.length; i++)
                marks[i] =Float.parseFloat(args[i]);
            float avg=0;
            int count=0;
            for(float x:marks)
                avg+=x;
            avg=avg/args.length;
            for(float x:marks)
            {
                if(x>avg)
                    count++;
            }  
            System.out.println("AVG: " + avg);
            System.out.println("no. of students who have scored more than avg are -"+count);
        } 
    }    
}
