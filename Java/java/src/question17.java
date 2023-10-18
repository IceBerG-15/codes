import java.util.*;
import java.io.*;

class Donor
{
    String name;
    int age;
    String address;
    long contact;
    Donor(String name, int age, String address, long contact)
    {
        this.name = name;
        this.address = address;
        this.age = age;
        this.contact = contact;
    }
    void display()
    {
        System.out.println("Donor Details: ");
        System.out.println("Name: " + name);
        System.out.println("age: " + age);
        System.out.println("Address: "+ address);
        System.out.println("Contact: "+ contact);
    }
}

class organDonorRegistration extends Donor implements Serializable
{
    String blood_group;
    String organ;
    organDonorRegistration(String name, int age, String address, long contact,String blood_group, String organ)
    {
        super(name, age, address, contact);
        this.blood_group = blood_group;
        this.organ = organ;
    }
    void display()
    {
        super.display();
        System.out.println("Blood Group: "+ blood_group);
        System.out.println("Organ: "+organ);
    }
}

class question17
{
    public static void main(String[] args) throws NotSerializableException,InvalidClassException,ClassNotFoundException,IOException
    {
        String name;
        int age;
        String address;
        long contact;
        String blood_group;
        String organ;
        Scanner sc = new Scanner(System.in);
        File file = new File("Java\\java\\src\\donorlist.ser");
        int n;
        System.out.println("enter n: ");
        n=sc.nextInt();
        FileOutputStream fos = new FileOutputStream(file);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        organDonorRegistration donor;
        ArrayList<organDonorRegistration> donorlist = new ArrayList<>();
        for(int i=0; i<n;i++)
        {
            System.out.println("Name: ");
            name=sc.next();
            System.out.println("age: ");
            age=sc.nextInt();
            System.out.println("Contact: ");
            contact=sc.nextLong();
            System.out.println("Blood Group: ");
            blood_group=sc.next();
            System.out.println("Organ: ");
            organ=sc.next();
            sc.nextLine();
            System.out.println("Address: ");
            address=sc.nextLine();
            donor = new organDonorRegistration(name,age, address, contact,blood_group,organ);
            donorlist.add(i, donor);
        }
        oos.writeObject(donorlist);
        oos.close();
        fos.close();
        
        FileInputStream fis = new FileInputStream(file);
        ObjectInputStream ois = new ObjectInputStream(fis);
        donorlist = (ArrayList<organDonorRegistration>)ois.readObject() ;
        for(organDonorRegistration o : donorlist)
            o.display();
        fis.close();
        ois.close();
    }
}