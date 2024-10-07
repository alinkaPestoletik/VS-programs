import java.util.Arrays;
import java.util.Scanner;
public class replace_element_in_array {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter array length: ");
        int size = input.nextInt(); 
        int numbers[] = new int[size]; 
        System.out.println("Insert array elements:");
        for (int i = 0; i < size; i++) 
            numbers[i] = input.nextInt();
        System.out.println(Arrays.toString(insert_element(numbers)));
    }

    private static int[] insert_element(int[] numbers) {
        Scanner scan = new Scanner(System.in);
        int index;
        System.out.printf("Element index (from 0 till %d): ", numbers.length - 1);
        index = scan.nextInt();
        System.out.println("Choose the value to insert: ");
        numbers[index] = scan.nextInt();
        return numbers;
    }
}
    