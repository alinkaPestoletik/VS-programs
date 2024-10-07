import java.util.Scanner;

public class count_vowels {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        String str1 = scan.next().toLowerCase();
        char[] vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
        int s = 0;
        for (int i=0; i < str1.length(); i++) {
            for (char vowel : vowels) {
                if (str1.charAt(i) == vowel) 
                    s++; }
                }
        System.out.println("Number of vowels is " + s);
    }
}