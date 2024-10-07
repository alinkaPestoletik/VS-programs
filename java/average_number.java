import java.util.Scanner;
public class average_number {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); 
        System.out.println("Enter array length: ");
        int size = input.nextInt(); 
        int numbers[] = new int[size]; 
        System.out.println("Insert array elements:");
        for (int i = 0; i < size; i++) 
            numbers[i] = input.nextInt();
        System.out.println("The average is " + calculateAverage(numbers));
    }

    private static float calculateAverage(int[] numbers) {
        float avg = 0;
        for (int number : numbers) 
            avg += number;
        avg /= numbers.length;
        return avg;
    }    
}
