import java.io.File;

public class check_path_type {
    public static void main(String[] args) {
    String path = "D:\\VS programs\\VS-programs\\java\\compare_strings.java";
    if (checkPath(path)) {
    System.out.println(path + " is a " + (isFile(path) ? "file" : "directory"));
    } else {
    System.out.println("Error: file doesn't exist!"); }
    }

    private static boolean checkPath(String path) {
        File file = new File(path);
        return file.exists();
    }

    private static boolean isFile(String path) {
        File file = new File(path);
        return file.isFile();
    }
}


