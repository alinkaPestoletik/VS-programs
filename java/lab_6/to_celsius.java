import java.util.Scanner;
public class to_celsius {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double fahrenheit = s.nextDouble();
        double celsius = (5.0 / 9.0) * (fahrenheit - 32);
        System.out.println(celsius);
    }
}

