import java.util.ArrayList;
import java.util.List;

public class shape{
    private String name;
    private String color;
    private List<shape> contains;

    public shape(String name,String color){
        this.name = name;
        this.color = color;
        contains = new ArrayList<shape>();
    }

    public void add(shape s){
        contains.add(s);
    }

    public void remove(shape s){
        contains.remove(s);
    }

    public List<shape> getContains(){
        return contains;
    }

    public String toString(){
        return ("Object: [Name: "+name+", color: "+color+"]");
    }

    public void printContains(){
        System.out.println(name+" contains:");
        for(shape s:contains){
            System.out.println(s);
        }
    }
}
