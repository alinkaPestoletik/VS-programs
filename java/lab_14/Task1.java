import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

public class Task1 {
    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<>();
        Random random = new Random();

        for (int i = 0; i < 10; i++) {
            numbers.add(random.nextInt());
        }

        numbers.stream().forEach(x -> System.out.print(x + " "));
        System.out.println();
        List<Integer> result = numbers.stream().filter(x -> x % 3 == 0).collect(Collectors.toList());
        result.stream().forEach(x -> System.out.print(Math.abs(x) + " "));
    }
}