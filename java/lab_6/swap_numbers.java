import java.util.Scanner; 

public class swap_numbers {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in); 
        int x = s.nextInt(); 
        int y = s.nextInt();
        int temporary = x;
        x = y;
        y = temporary;
        System.out.println("First number = " + x);
        System.out.println("Second number = " + y);
    }
}
