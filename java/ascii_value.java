import java.util.Scanner;

public class ascii_value {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in); 
        char ch = s.next().charAt(0);
        int ascii = (int) ch;
        System.out.println(ascii);
    }
    
}
