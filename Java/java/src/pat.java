class pat
{
    public static void main(String[] args)
    {
        int size=9;
        int counter=1;
        for (int i=0; i<size; i++)
        {
            int count=1;
            while(count<=counter){
                System.out.print(count+"  ");
                count++;
            }
            System.out.println();
            if(i<size/2)
                counter+=2;
            else   
                counter-=2;
        }
    }
}