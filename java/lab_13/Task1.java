import java.util.ArrayList;
import java.util.List;

public class Task1 {
    public static void main(String[] args) {
        Library<Book> bookLibrary = new Library<>();
        Library<Video> videoLibrary = new Library<>();
        Library<Newspaper> newspaperLibrary = new Library<>();
        Book kolobok = new Book("Kolobok", "People", 10, 1873);
        bookLibrary.addInfo(kolobok);
        bookLibrary.deleteInfo(0);
    }
}

abstract class Media {
    private String type;
    private String title;
    private String author;
    private int year;
    public Media(String type, String title, String author, int year) {
        this.type = type;
        this.title = title;
        this.author = author;
        this.year = year;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getAuthor() {
        return author;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getYear() {
        return year;
    }

    public abstract void displayAllInfo();
}

class Book extends Media {
    private int numberOfPages;

    public Book(String title, String author, int numberOfPages, int year) {
        super("Book", title, author, year);
        this.numberOfPages = numberOfPages;
    }

    @Override
    public void displayAllInfo() {
        System.out.println("Book " + getTitle() + " is written by " + getAuthor() + " in " + getYear()
        + " year and consists of " + numberOfPages + " pages.");
    }
}

class Newspaper extends Media {
    private String publicationDate;
    private int sections;
    public Newspaper(String title, String author, int year, String publicationDate, int sections) {
        super("Newspaper", title, author, year);
        this.publicationDate = publicationDate;
        this.sections = sections;
    }

    @Override
    public void displayAllInfo() {
        System.out.println("Newspaper " + getTitle() + " is written by " + getAuthor() + " was published at "
        + publicationDate + getYear() + "and consists of " + sections + " sections.");
    }
}

class Video extends Media {
    private String genre;
    private int runtime;
    public Video(String title, String author, int year, String genre, int runtime) {
        super("Video", title, author, year);
        this.genre = genre;
        this.runtime = runtime;
    }

    @Override
    public void displayAllInfo() {
        System.out.println("Video " + getTitle() + " is made by " + getAuthor() + " in " + getYear()
        + " year, has genre " + genre + " and durention " + runtime + " .");
    }
}

class LibraryGeneric<T extends Media> {
    private List<T> items = new ArrayList<>();
    public void addInfo(T source) {
        if (!items.contains(source)) {
            items.add(source);
        } else {
            System.out.println("This source is already in library!");
        }
    }

    public void deleteInfo(int index) {
        items.remove(index);
    }
}

class LibraryBook {
    private static int numberOfBooks = 0;
    private static Media[] books = new Media[numberOfBooks];

    public void listBooks() {
        for (int i = 0; i < numberOfBooks; i++) {
            ((Book) books[i]).displayAllInfo();
        }
    }

    private void makeBook() {
        for (int i = 0; i < numberOfBooks; i++) {
            books[i] = (Book) books[i];
        }
    }

    public void add(Media object) {
        Media[] newArray = new Media[books.length + 1];
        for (int i = 0; i < books.length; i++) {
            newArray[i] = books[i];
        }
        newArray[newArray.length - 1] = object;
        books = newArray;
        numberOfBooks += 1;
        makeBook();
    }

    public void delete(int index) {
        Media[] newArray = new Media[books.length - 1];
        for (int i = 0; i < index; i++) {
            newArray[i] = books[i];
        }
        for (int i = index; i < books.length - 1; i++) {
            newArray[i] = books[i + 1];
        }
        books = newArray;
        numberOfBooks -= 1;
        makeBook();
    }
}


class LibraryVideo {
    private static int numberOfVideo = 0;
    private static Media[] video = new Media[numberOfVideo];

    public void listVideo() {
        for (int i = 0; i < numberOfVideo; i++) {
            ((Video) video[i]).displayAllInfo();
        }
    }

    private void makeVideo() {
        for (int i = 0; i < numberOfVideo; i++) {
            video[i] = (Video) video[i];
        }
    }

    public void add(Media object) {
        Media[] newArray = new Media[video.length + 1];
        for (int i = 0; i < video.length; i++) {
            newArray[i] = video[i];
        }
        newArray[newArray.length - 1] = object;
        video = newArray;
        makeVideo();
    }

    public void delete(int index) {
        Media[] newArray = new Media[video.length - 1];
        for (int i = 0; i < index; i++) {
            newArray[i] = video[i];
        }
        for (int i = index; i < video.length - 1; i++) {
            newArray[i] = video[i + 1];
        }
        video = newArray;
        makeVideo();
    }
}


class LibraryNewspaper {
    private static int numberOfNewspaper = 0;
    private static Media[] newspapers = new Media[numberOfNewspaper];

    public void listVideo() {
        for (int i = 0; i < numberOfNewspaper; i++) {
            ((Video) newspapers[i]).displayAllInfo();
        }
    }

    private void makeNewspaper() {
        for (int i = 0; i < numberOfNewspaper; i++) {
            newspapers[i] = (Newspaper) newspapers[i];
        }
    }

    public void add(Media object) {
        Media[] newArray = new Media[newspapers.length + 1];
        for (int i = 0; i < newspapers.length; i++) {
            newArray[i] = newspapers[i];
        }
        newArray[newArray.length - 1] = object;
        newspapers = newArray;
        makeNewspaper();
    }

    public void delete(int index) {
        Media[] newArray = new Media[newspapers.length - 1];
        for (int i = 0; i < index; i++) {
            newArray[i] = newspapers[i];
        }
        for (int i = index; i < newspapers.length - 1; i++) {
            newArray[i] = newspapers[i + 1];
        }
        newspapers = newArray;
        makeNewspaper();
    }
}

