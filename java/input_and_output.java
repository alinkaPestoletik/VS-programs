import java.util.Scanner; // import the package which contains the Scanner class

public class input_and_output {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in); // define a scanner (to use it for reading the input)
        int x = s.nextInt(); // read an integer from the input
        String word = s.next(); // read a string (separated by space)
        String sentence = s.nextLine(); // read a string (separated by new line)
        System.out.println("Hello world!");
        System.out.println(x);
        System.out.println(word);
        System.out.println(sentence);
        }
    }
        
