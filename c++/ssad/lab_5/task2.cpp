#include <iostream>
#include <memory>

class Test;
using namespace std;

class Box {
private:
    int a;

public:
    Box() : a(5) {
    }

    Box(int x) : a(x) {
    }

    ~Box() { return; };
    int getA() { return a; }
};

int createUnique() {
    unique_ptr<Box> box(new Box());
    unique_ptr<Box> box2;
    box2 = std::move(box);
    return box2->getA();
}

void create_shared_ptr() {
    shared_ptr<Box> box(new Box());
    shared_ptr<Box> box2(new Box(10));
    cout << box->getA() << endl;
    cout << box.use_count() << endl;
    cout << box2->getA() << endl;
    box2 = box;
    cout << box2->getA() << endl;
    cout << box.use_count() << endl;
}

void explore_weak_ptr() {
    shared_ptr<Box> box(make_shared<Box>());
    weak_ptr<Box> weak_box(box);
    // box.reset();
    cout << weak_box.expired() << endl;
    shared_ptr<Box> box2 = weak_box.lock();
    cout << box2 -> getA();
}

int main() {
    explore_weak_ptr();
    return 0;
}
