#include <iostream>
#include <vector>
using namespace std;

class Animal {
    protected:
        string name;
        int age;
    public:
        virtual void makeSound() const {
            cout << "The animal is making sound!" << endl;
        }
        
        Animal(const std::string& name, int age) : name(name), age(age) {}

        string getName() const {
            return name;
        }

        int getAge() const {
            return age;
        }

        virtual ~Animal() {}
};

class Cat : public Animal {
public:
    Cat(const string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

class LandAnimal : virtual public Animal {
    public:
        LandAnimal(const std::string& name, int age) : Animal(name, age) {}

        virtual void walk() const {
            cout << "The wild animal is walking" << endl;
        }

        void makeSound() const override {
            cout << "Raaar" << endl;
        }
};

class WaterAnimal : virtual public Animal {
    public:
        WaterAnimal(const std::string& name, int age) : Animal(name, age) {}

        virtual void swim() const {
            cout << "The animal is swimming" << endl;
        }

        void makeSound() const override {
            cout << "Bull bull bull" << endl;
        }
};

class Lion : virtual public LandAnimal {
    public:
        Lion(const string& name, int age) : Animal(name, age), LandAnimal(name, age) {}

        void makeSound() const override {
            cout << "Roar!" << endl;
        }

        void walk() const override {
            cout << name << " is walk on the land!" << endl;
        }
};

class Dolphin : virtual public WaterAnimal {
    public:
        Dolphin(const string& name, int age) : Animal(name, age), WaterAnimal(name, age) {}

        void makeSound() const override {
            cout << "Click!" << endl;
        }

        void swim() const override {
            cout << name << " is swimming!" << endl;
        }
};

class Frog : public LandAnimal, public WaterAnimal {
public:
    Frog(const string& name, int age) : Animal(name, age), LandAnimal(name, age), WaterAnimal(name, age) {}

    void makeSound() const override {
        cout << "Ribbit!" << endl;
    }

    void walk() const override {
        cout << name << " is hopping on the land!" << endl;
    }

    void swim() const override {
        cout << name << " is swimming in the pond!" << endl;
    }
};

int main() {
    std::vector<Animal*> zoo;

    zoo.push_back(new Lion("Leo", 3));
    zoo.push_back(new Dolphin("Dolp", 6));
    zoo.push_back(new Frog("Frew", 2));

    for (Animal *animal : zoo) {
        animal->makeSound();

        if (Lion* lion = dynamic_cast<Lion*>(animal)) {
            lion->walk(); 
        } else if (Dolphin* dolphin = dynamic_cast<Dolphin*>(animal)) {
            dolphin->swim(); 
        } else if (Frog* frog = dynamic_cast<Frog*>(animal)) {
            frog->walk(); 
            frog->swim(); 
        }
    }

    for (Animal *animal : zoo) {
        delete animal; 
    }
    zoo.clear();

    return 0;
}