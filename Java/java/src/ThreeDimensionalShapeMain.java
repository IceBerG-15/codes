import java.util.Scanner;

abstract class ThreeDimensionalShape
{
    Scanner s = new Scanner(System.in);
    abstract public void getData();
    abstract public void areaShapes();
}

class Cube extends ThreeDimensionalShape
{
    int length;
    public void getData()
    {
        System.out.println("enter length: ");
        length=s.nextInt();
    }
    public void areaShapes()
    {
        int ar;
        ar=6*length*length;
        System.out.println("Area: "+ar);
    }
}

class RectangularPrism extends ThreeDimensionalShape
{
    int len,width,height;
    public void getData()
    { 
        System.out.println("enter length: ");
        len=s.nextInt();
        System.out.println("enter width: ");
        width=s.nextInt();
        System.out.println("enter height: ");
        height=s.nextInt();
    }
    public void areaShapes()
    {
        int ar;
        ar=2*(width*len+height*len+height*width);
        System.out.println("Area: "+ar);
    }
}

class ThreeDimensionalShapeMain 
{
    public static void main(String[] args) 
    {
        ThreeDimensionalShape td;
        td=new Cube();
        td.getData();
        td.areaShapes();
        ThreeDimensionalShape t;
        t=new RectangularPrism();
        t.getData();
        t.areaShapes();
    }
}