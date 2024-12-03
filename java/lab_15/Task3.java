import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Task3 {
    public static void main(String[] args) {
        List<Book> books = new ArrayList<>();
        ReaderLibrary library = new ReaderLibrary();
        String PATH = "D:\\VS programs\\VS-programs\\java\\lab_15\\test.dat";
        Book harryPotter = new Book("Johan Rouling", "some title", 10, 10, 10);
        books.add(harryPotter);
        library.addMyreadBooks(books, PATH);
        List<Book> serializedBooks = library.readMyreadBooks(PATH);
        serializedBooks.forEach(Object::toString);
    }
}

class Book implements Serializable{
    String author;
    String title;
    int issueYear;
    int pageNumber;
    int bookmark;
    public Book(String author, String title, int issuesYear, int pageNumber, int bookmark) {
        this.author = author;
        this.title = title;
        this.issueYear = issuesYear;
        this.pageNumber = pageNumber;
        this.bookmark = bookmark;
    }

}

class ReaderLibrary {

    public ReaderLibrary() {

    }
    public void addMyreadBooks(List<Book> books, String serializedPath) {
        try(FileOutputStream fileOutputStream = new FileOutputStream(serializedPath);
        ObjectOutputStream objectOutputStream = new ObjectOutputStream(fileOutputStream)) {
            objectOutputStream.writeObject(books);
        } catch (IOException ex) {
            ex.getMessage();
        }
    }

    public void someVoidFunc(){
        System.out.println("hello");
    }

    public List<Book> readMyreadBooks(String serializedPath) {
        List<Book> books = new ArrayList<>();
        try(FileInputStream fileIn = new FileInputStream(serializedPath);
        ObjectInputStream in = new ObjectInputStream(fileIn)) {
            books = (List<Book>) in.readObject();
        } catch (IOException | ClassNotFoundException ex) {
            ex.getMessage();
        }
        return books;
    }
}