import java.util.Scanner;

public class MedianStudent {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        scanner.nextLine();
        
        Student[] students = new Student[n];
        
        for (int i = 0; i < n; i++) {
            int score = scanner.nextInt();
            scanner.nextLine();
            String name = scanner.nextLine().trim();
            students[i] = new Student(score, name);
        }
        
        scanner.close();
        
        // Находим "среднего" студента
        Student medianStudent = findMedian(students, 0, n);
        
        // Выводим результат
        System.out.println(medianStudent.toString());
    }
    
    // Класс для хранения информации о студенте
    static class Student implements Comparable<Student> {
        int score;
        String name;
        
        Student(int score, String name) {
            this.score = score;
            this.name = name;
        }
        
        @Override
        public int compareTo(Student other) {
            return Integer.compare(this.score, other.score);
        }
        
        @Override
        public String toString() {
            return name;
        }
    }

    // Функция для нахождения медианы списка студентов
    private static Student findMedian(Student[] students, int start, int end) {
        if (end - start <= 1) {
            return students[start]; // Если остался один студент, возвращаем его
        }
        
        // Массив для хранения медиан
        Student[] medians = new Student[(end - start + 4) / 5];
        
        // Разбиваем студентов на группы по 5 человек
        int index = 0;
        for (int i = start; i < end; i += 5) {
            int groupSize = Math.min(end - i, 5);
            
            // Сортируем группу и находим медиану
            sortStudents(students, i, i + groupSize - 1);
            medians[index++] = students[i + (groupSize - 1) / 2];
        }
        
        // Рекурсивно ищем медиану среди медиан
        return findMedian(medians, 0, index);
    }

    // Быстрая сортировка для группы студентов
    private static void sortStudents(Student[] students, int left, int right) {
        if (left >= right) {
            return;
        }
        
        int pivot = partition(students, left, right);
        sortStudents(students, left, pivot - 1);
        sortStudents(students, pivot + 1, right);
    }

    // Метод разбиения для быстрой сортировки
    private static int partition(Student[] students, int left, int right) {
        Student pivot = students[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (students[j].compareTo(pivot) < 0) {
                i++;
                swap(students, i, j);
            }
        }
        
        swap(students, i + 1, right);
        return i + 1;
    }

    // Обмен местами двух студентов
    private static void swap(Student[] students, int i, int j) {
        Student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
    }
}