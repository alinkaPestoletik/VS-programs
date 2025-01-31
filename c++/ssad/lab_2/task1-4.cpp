#include <iostream>
using namespace std;


class Cube {
private:
    unsigned int a;
public:
    Cube() {
        this->a = 0;
    }

    Cube(unsigned int a) {
        this->a = a;
    }



    ~Cube() {return;}

    int getA() {
        return a;
    }
};

class Box {
private:
    unsigned int length;
    unsigned int width;
    unsigned int height;

public:
    Box() {
        this->length = 0;
        this->width = 0;
        this->height = 0;
    }

    Box(unsigned int length, unsigned int width, unsigned int height) {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    Box(Box &b) {
        this->length = b.length;
        this->width = b.width;
        this->height = b.height;
    }

    ~Box(){return ;}

    Box &operator=(Box &b) {
        this->length = b.length;
        this->width = b.width;
        this->height = b.height;
        return *this;
    }

    Box &operator*=(unsigned num) {
        scale(num);
        return *this;
    }

    Box& operator = (Cube &b) {
        this->length = b.getA();
        this->width = b.getA();
        this->height = b.getA();
        return *this;
    }

    bool operator==(Box& other) {
        if (this->length == other.length && this->width == other.width && this->height == other.height) {
            return true;
        }
        return false;
    }



    unsigned getVolume() {
        return this->length * this->width * this->height;
    }

    void scale(unsigned scaleValue) {
        this->length *= scaleValue;
        this->width *= scaleValue;
        this->height *= scaleValue;
    }

    bool isBigger(Box& b) {
        return this->getVolume() > b.getVolume();
    }

    bool isSmaller(Box& b) {
        return this->getVolume() < b.getVolume();
    }

};

int main() {
    // Box obj(10,10,10);
    // Box obj2(10,10,10);
    // unsigned int test = 10;
    // bool result = obj == obj2;
    // obj*=test;
    // cout << obj.getVolume() << endl;
    // cout << obj.isSmaller(obj2) << endl;
    // cout << result << endl;
    Box obj(10,10,10);
    Cube obj2(5);
    obj = obj2;
    cout << obj.getVolume() << endl;
    return 0;
}