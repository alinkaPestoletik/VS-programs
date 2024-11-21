import java.util.HashMap;
import java.util.Map;

class Animal {
    private int id;
    private String nickname;
    private Owner owner;

    public Animal(int id, String nickname, Owner owner) {
        this.id = id;
        this.nickname = nickname;
        this.owner = owner;
    }

    public int getId() {
        return id;
    }

    public String getNickname() {
        return nickname;
    }

    public Owner getOwner() {
        return owner;
    }
}

class Cat extends Animal {
    private int purLoudness;

    public Cat(int id, String nickname, Owner owner, int purLoudness) {
        super(id, nickname, owner);
        this.purLoudness = purLoudness;
    }

    public int getPurLoudness() {
        return purLoudness;
    }
}

class Snake extends Animal {
    private int venomDanger;

    public Snake(int id, String nickname, Owner owner, int venomDanger) {
        super(id, nickname, owner);
        this.venomDanger = venomDanger;
    }

    public int getVenomDanger() {
        return venomDanger;
    }
}

class Rabbit extends Animal {
    private int earLength;

    public Rabbit(int id, String nickname, Owner owner, int earLength) {
        super(id, nickname, owner);
        this.earLength = earLength;
    }

    public int getEarLength() {
        return earLength;
    }
}

class Owner {
    private String name;
    private String surname;
    private int age;

    public Owner(String name, String surname, int age) {
        this.name = name;
        this.surname = surname;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public int getAge() {
        return age;
    }
}

class VeterinaryClinic {
    private static Map<Integer, Animal> animals = new HashMap<>();

    public void addPets(Animal... pets) {
        for (Animal pet : pets) {
            animals.put(pet.getId(), pet);
        }
    }

    public void displayPets() {
        for (Animal animal : animals.values()) {
            System.out.println("ID: " + animal.getId());
            System.out.println("Nickname: " + animal.getNickname());
            System.out.println("Owner: " + animal.getOwner().getName() + " " + animal.getOwner().getSurname());
            if (animal instanceof Cat) {
                Cat cat = (Cat) animal;
                System.out.println("Purr loudness: " + cat.getPurLoudness());
            } else if (animal instanceof Snake) {
                Snake snake = (Snake) animal;
                System.out.println("Venom danger: " + snake.getVenomDanger());
            } else if (animal instanceof Rabbit) {
                Rabbit rabbit = (Rabbit) animal;
                System.out.println("Ear length: " + rabbit.getEarLength());
            }
            System.out.println();
        }
    }
}

public class Task3 {
    public static void main(String[] args) {
        VeterinaryClinic clinic = new VeterinaryClinic();

        Owner owner1 = new Owner("Alina", "Pestova", 18);
        Owner owner2 = new Owner("Denis", "Nurmuhametov", 17);

        Cat cat1 = new Cat(1, "Tishka", owner1, 5);
        Snake snake1 = new Snake(2, "Python", owner2, 8);
        Rabbit rabbit1 = new Rabbit(3, "Bunny", owner1, 15);
        clinic.addPets(cat1, snake1, rabbit1);

        // Trying to add a pet with the same ID
        Cat cat2 = new Cat(1, "Yashka", owner2, 3);
        clinic.addPets(cat2);

        clinic.displayPets();
    }
}

