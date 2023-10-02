class pattern 
{
    public static void main(String[] args)
    {
        int k=1;
        int l=5;
        for(int i=0;i<7;i++)
        {
            if(i<4)
            {
                for(int j=1;j<=k;j++)
                    System.out.print(j+"  ");
                k+=2;
                System.out.println();
            }
            else
            {
                for(int j=1;j<=l;j++)
                    System.out.print(j+"  ");
                l-=2;
                System.out.println();
            }
        }
    }
}


