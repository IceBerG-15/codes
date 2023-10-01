
class catpractice3 {
    public static void main(String[] args) {
        float[][] array=new float[3][3];
        int k=0;int i,j;
        for(i=0; i<3; i++)
        {
            array[i] = new float[3];
            for(j=0; j<3; j++)
                array[i][j]=Float.parseFloat(args[k++]);
        }
        float max;
        for(i=0; i<array.length; i++)
        {
            max=array[i][0];
            for(j=1; j<array[i].length; j++)
            {
                if(array[i][j]>max)
                    max=array[i][j];
            }
            System.out.println("highest rainfall in district-"+(i+1)+" "+max);
        }
    }
}
