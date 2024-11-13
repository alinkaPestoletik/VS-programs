import java.util.Scanner;

public class compare_strings {
    public static void main(String[] args) {
        Scanner strScann = new Scanner(System.in);
        String str1 = strScann.next();
        String str2 = strScann.next();
        System.out.print("strings are " + (str1.equals(str2) ? "equal" : "not equal"));
    }
}
