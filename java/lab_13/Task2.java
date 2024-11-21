import java.util.HashSet;
import java.util.Set;

class Animal {
    protected String nickname;

    public Animal(String nickname) {
        this.nickname = nickname;
    }

    public void voice() {
        System.out.println("Generic animal sound");
    }
}

class Cat extends Animal {
    private int purLoudness;

    public Cat(String nickname, int purLoudness) {
        super(nickname);
        this.purLoudness = purLoudness;
    }

    @Override
    public void voice() {
        System.out.println(nickname + " purrs with loudness " + purLoudness);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Cat cat = (Cat) o;
        return purLoudness == cat.purLoudness && nickname.equals(cat.nickname);
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + purLoudness;
        result = prime * result + ((nickname == null) ? 0 : nickname.hashCode());
        return result;
    }
}

class Dog extends Animal {
    private int barkingLoudness;

    public Dog(String nickname, int barkingLoudness) {
        super(nickname);
        this.barkingLoudness = barkingLoudness;
    }

    @Override
    public void voice() {
        System.out.println(nickname + " barks with loudness " + barkingLoudness);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        Dog dog = (Dog) o;
        return barkingLoudness == dog.barkingLoudness && nickname.equals(dog.nickname);
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + barkingLoudness;
        result = prime * result + ((nickname == null) ? 0 : nickname.hashCode());
        return result;
    }
}

public class Task2 {
    public static void displayAnimals(Set<? extends Animal> animals) {
        for (Animal animal : animals) {
            System.out.println(animal.nickname);
        }
    }

    public static void makeTalk(Set<? extends Animal> animals) {
        for (Animal animal : animals) {
            animal.voice();
        }
    }

    public static void addAnimals(Set<? super Animal> animals) {
        animals.add(new Cat("Yashka", 3));
        animals.add(new Dog("Leo", 10));
    }

    public static void main(String[] args) {
        Set<Cat> cats = new HashSet<>();
        cats.add(new Cat("Tishka", 5));
        cats.add(new Cat("Pushok", 3));
        cats.add(new Cat("Pushok", 3));

        Set<Dog> dogs = new HashSet<>();
        dogs.add(new Dog("Barbos", 5));
        dogs.add(new Dog("Sharik", 8));

        Set<Animal> allAnimals = new HashSet<>();
        addAnimals(allAnimals);

        displayAnimals(cats);
        makeTalk(cats);

        displayAnimals(dogs);
        makeTalk(dogs);

        displayAnimals(allAnimals);
        makeTalk(allAnimals);
    }
}
