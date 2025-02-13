#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class Rectangle : public Shape {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};

class Circle : public Shape {
public:
    double radius;

    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }
};

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(4.0);
    Shape& shape = rectangle;

    const Rectangle* rectPtr = static_cast<const Rectangle*>(&shape); 

    if (dynamic_cast<Circle*>(&shape) != nullptr) {
        cout << "shape is a Circle" << endl;
    } else {
        cout << "shape is not a Circle" << endl;
    }

    Rectangle* nonConstRectPtr = const_cast<Rectangle*>(rectPtr);

    int intValue = 20;
    double* doublePtr = reinterpret_cast<double*>(&intValue);

    return 0;
}