import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class index_of_character {
    
    public static void main(String[] args) {
        Map<Character,Integer> dict = new HashMap<Character,Integer>();
        
        for (char c = 'a'; c <= 'z'; c++) {
            for (int x=1; x<27; x++) {
                dict.put(c, c+1-'a');
            }
        }
        
        Scanner s = new Scanner(System.in); 
        String str = s.next().toLowerCase();;
        char ch = str.charAt(0);

        System.out.println(dict.get(ch));

    }
}
    