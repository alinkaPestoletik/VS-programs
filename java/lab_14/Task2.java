import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Task2 {

    public static void main(String[] args) {
        List<String> strings = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            String randomString = generateRandomString(random.nextInt(10) + 5);
            strings.add(randomString);
            strings.add(randomString);
        }

        List<String> filteredStrings = strings.stream()
                .filter(s -> !s.isEmpty() && s.matches("[a-zA-Z]+"))
                .distinct()
                .sorted()
                .collect(Collectors.toList());

        System.out.println(filteredStrings);
    }

    private static String generateRandomString(int length) {
        Random random = new Random();
        String alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            int index = random.nextInt(alphabet.length());
            sb.append(alphabet.charAt(index));
        }
        return sb.toString();
    }
}

