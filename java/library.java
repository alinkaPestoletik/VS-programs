public class library {
    class Auther {
        private String name;
        private String email;
        private String gender;

        public Author(String name, String email, String gender) {
            this.name = name;
            this.email = email;
            this.gender = gender;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getEmail() {
            return email;
        }

        public void setEmail(String email) {
            this.email = email;
        }

        public String getGender() {
            return gender;
        }

        public void setGender(String gender) {
            this.gender = gender;
        }
    }


    class Book {
        private String name;
        private Author author;
        private double price;
        private int quantity;

        public Book(String name, Author author, double price, int quantity) {
            this.name = name;
            this.author = author;
            this.price = price;
            this.quantity = quantity;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public Author getAuthor() {
            return author;
        }

        public void setAuthor(Author author) {
            this.author = author;
        }

        public double getPrice() {
            return price;
        }

        public void setPrice(double price) {
            this.price = price;
        }

        public int getQuantity() {
            return quantity;
        }

        public void setQuantity(int quantity) {
            this.quantity = quantity;
        }
    }

    class Library {
        private Book[] books;

        public Library(Book[] books) {
            this.books = books;
        }

        public void updateBook(int index, String name, double price, int quantity) {
            if (index >= 0 && index < books.length) {
                books[index].setName(name);
                books[index].setPrice(price);
                books[index].setQuantity(quantity);
                System.out.println("Book updated successfully!");
            } else {
                System.out.println("Invalid book index.");
            }
        }

        public void displayBookInformation() {
            if (books.length == 0) {
                System.out.println("No books in the library.");
            } else {
                for (Book book : books) {
                    System.out.println("Book Name: " + book.getName());
                    System.out.println("Author: " + book.getAuthor().getName());
                    System.out.println("Price: " + book.getPrice());
                    System.out.println("Quantity: " + book.getQuantity());
                    System.out.println("----------------------");
                }
            }
        }

        public static void main(String[] args) {
            Author author1 = new Author("Jane Austen", "jane.austen@example.com", "Female");
            Author author2 = new Author("Charles Dickens", "charles.dickens@example.com", "Male");

            Book book1 = new Book("Pride and Prejudice", author1, 10.99, 5);
            Book book2 = new Book("A Tale of Two Cities", author2, 12.99, 3);

            Book[] libraryBooks = {book1, book2};
            Library library = new Library(libraryBooks);

            library.displayBookInformation();

            library.updateBook(0, "Pride and Prejudice (Revised)", 11.99, 6);
            System.out.println("\nUpdated Book Information:");
            library.displayBookInformation();
        }
    }
}