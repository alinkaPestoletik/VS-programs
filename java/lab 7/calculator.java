import java.util.Scanner;
public class calculator {
    public static float calculate(int num1, char operator, int num2) {
        switch (operator) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 == 0) {
                    System.out.println("Error: Division by zero is not allowed.");
                    return -1; }
                return (float) num1 / num2;
            default:
                System.out.println("Error: Invalid operator.");
                return -1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the first number: ");
        int num1 = scanner.nextInt();

        System.out.print("Enter the operator (+, -, *, /): ");
        char operator = scanner.next().charAt(0);

        System.out.print("Enter the second number: ");
        int num2 = scanner.nextInt();
        
        float result = calculate(num1, operator, num2);
        if (result != -1) {
            System.out.println("Result: " + result);
        }
    }
}