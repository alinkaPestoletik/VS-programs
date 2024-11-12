public class animal {
    protected String name;
    protected double height;
    protected double weight;
    protected String color;

    public animal() {
        this.name = "unknown";
        this.height = 0;
        this.weight = 0;
        this.color = "unknown";
    }

    public animal(String i_n, double i_h, double i_w, String i_c){
        this.name = i_n;
        this.height = i_h;
        this.weight = i_w;
        this.color = i_c;
    }

    public void eat() {
        System.out.printf("%s%s\n", this.name, " is eating");
    } 

    public void sleep() {
        System.out.printf("%s%s\n", this.name, "is sleeping");
    }

    public void make_sound() {
        System.out.printf("%s%s\n", this.name, "is making sound");
    }

    public static class Cow extends animal{
        public Cow() {
            super();
        }

        public Cow(String i_n, double i_h, double i_w, String i_c) {
            super(i_n, i_h, i_w, i_c);
        }

        @Override
        public void eat() {
            System.out.printf("%s %s\n", this.name, "is chewing grass");
        }

        public void make_sound() {
            System.out.println("Mooo");;
        }
    }

    public static class Cat extends animal {
        public Cat() {
            super();
        }

        public Cat(String i_n, double i_h, double i_w, String i_c) {
            super(i_n, i_h, i_w, i_c);
        }

        @Override
        public void eat() {
            System.out.printf("%s %s\n", this.name, "is drinking milk");
        }

        public void make_sound() {
            System.out.printf("Meow");
        }
    }

    public static class Dog extends animal {
        public Dog() {
            super();
        }

        public Dog(String i_n, double i_h, double i_w, String i_c) {
            super(i_n, i_h, i_w, i_c);
        }

        @Override
        public void eat() {
            System.out.printf("%s %s\n", this.name, "is eating botes");
        }

        public void make_sound() {
            System.out.printf("Wof");
        }
    }

    public static void main(String[] args) {
        Cat tishka = new Cat("tishka", 20, 3, "white");
        tishka.eat();
    }
}

