#include <iostream>
using namespace std;

/*
Topic: Polymorphism
1) Compile-time: function overloading
2) Run-time: method overriding + virtual
*/

class Print {
public:
    void show(int x) {
        cout << "Integer: " << x << '\n';
    }

    void show(double x) {
        cout << "Double: " << x << '\n';
    }
};

class Animal {
public:
    virtual ~Animal() = default;

    virtual void sound() const {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() const override {
        cout << "Dog barks\n";
    }
};

int main() {
    Print p;
    p.show(10);
    p.show(10.5);

    Animal* a = new Dog();
    a->sound(); // runtime polymorphism
    delete a;

    return 0;
}
