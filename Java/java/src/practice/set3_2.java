package practice;
import java.util.Scanner;
import java.io.*;

class PurchaseDetails implements Serializable {
    String name;
    int[] a;
    PurchaseDetails(){
        int gn;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter your name: ");
        name = sc.next();
        System.out.println("enter quantity of grocery: ");
        gn = sc.nextInt();
        a = new int[gn];
        for(int j=0; j<a.length; j++){
            System.out.println("enter grocery-id: ");
            a[j] = sc.nextInt();
        }
    }
    PurchaseDetails(String name, int[] a){
        this.name = name;
        this.a = a;
    }
}

public class set3_2 {
    public static void main(String[] args) throws NotSerializableException,InvalidClassException,ClassNotFoundException,IOException,FileNotFoundException{
        String name;
        int n,gn;
        Scanner sc = new Scanner(System.in);
        System.out.println("enter n: ");
        n = sc.nextInt();
        PurchaseDetails[] pd = new PurchaseDetails[n];
        for(int i=0; i<n; i++){
            System.out.println("enter your name: ");
            name = sc.next();
            System.out.println("enter quantity of grocery: ");
            gn = sc.nextInt();
            int[] a = new int[gn];
            for(int j=0; j<a.length; j++){
                System.out.println("enter grocery-id: ");
                a[j] = sc.nextInt();
            }
            pd[i] = new PurchaseDetails(name, a);
        }
        File file = new File("C:\\Python310\\codes\\Java\\java\\src\\practice\\PurchaseDetails.ser");
        // opening file output stream for writing the object
        FileOutputStream fos = new FileOutputStream(file);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(pd);
        oos.close();
        fos.close();
        // opening file input stream for reading
        FileInputStream fis = new FileInputStream(file);
        ObjectInputStream ois = new ObjectInputStream(fis);
        Object ob = ois.readObject();
        pd = (PurchaseDetails[]) ob;
        for(PurchaseDetails p : pd){
            System.out.println(p.name);
            System.out.println("grocery-id: ");
            for(int k=0;k<p.a.length;k++)
                System.out.println("  "+p.a[k]);
        }
        ois.close();
        fis.close();
    }
}
