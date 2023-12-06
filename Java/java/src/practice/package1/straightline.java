package practice.package1;

public class straightline {
    int x1,x2,y1,y2;
    public straightline(int x1,int y1,int x2,int y2){
        this.x1 = x1;
        this.x2 = x2;
        this.y1 = y1;
        this.y2 = y2;
    }
    public double find_slope(){
        double slope;
        slope = (y2-y1)/(x2-x1);
        return slope;
    }
}
