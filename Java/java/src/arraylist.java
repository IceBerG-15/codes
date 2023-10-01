import java.util.ArrayList;

public class arraylist {
    public static void main(String[] args){
        ArrayList<String> food=new ArrayList<String>();  
        //here we can only use reference variables, so in case we want to use primitive types we will specify it using wrapper class
        food.add("Pizza");                      //adds element in the list
        food.add(1,"burger");       //adds element in the given index of list
        food.remove(1);                     //removes element present at the index
        for(int i=0;i<food.size();i++){           //size method is used just like length method in string
            System.out.println(food.get(i));      //we use get method to get the element at the index
        }
    }
}
