// import java.util.*;


class command_line 
{
    public static void main(String[] args) 
    {
        int[] array=new int[args.length];
        int j=0;
        try 
        {
            for(int i = 0; i < args.length;i++)
                array[j++] = Integer.parseInt(args[i]);
        } 
        catch (Exception e) {
            System.out.println(e);
        }
        for(int k:array)
            System.out.println(k);
    }
}
