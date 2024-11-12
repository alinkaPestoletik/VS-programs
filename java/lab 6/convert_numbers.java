import java.util.Scanner;
public class convert_numbers {
    public static void main(String[] args) {
        System.out.println("Print the integer value: ");
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        System.out.printf("in decimal: %d,%n" + "in hexadecimal: %h,%n" + "in binary: %s", number, number, Integer.toBinaryString(number));
    }
}
            

    