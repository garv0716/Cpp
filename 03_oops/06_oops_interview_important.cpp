#include <cstring>
#include <iostream>
#include <string>
using namespace std;

/*
OOPS INTERVIEW IMPORTANT: Quick Q&A + runnable code

Q1) Class vs Object?
-> Class blueprint hota hai, Object us class ka real instance.

Q2) Encapsulation kya hai?
-> Data + methods ko ek unit me pack karna, private members se data hide karna.

Q3) Abstraction kya hai?
-> "What" dikhana, "How" hide karna. Abstract class/interface use hoti hai.

Q4) Inheritance kyu use karte hain?
-> Code reusability + logical relationship (is-a).

Q5) Polymorphism kitne type?
-> Compile-time (overloading), Run-time (overriding + virtual).

Q6) Virtual destructor kyu important?
-> Base pointer se derived object delete karte time proper cleanup ke liye.

Q7) Deep copy vs shallow copy?
-> Pointer/resource classes me custom copy constructor + assignment se deep copy.

Q8) static member/function?
-> Class-level data/function, object independent.

Q9) friend function?
-> Non-member function jo class ke private/protected members access kar sake.

Q10) Operator overloading?
-> Operators ko user-defined types ke liye customize karna.
*/

// 1) Class + Encapsulation
class Student {
private:
    int rollNo;
    string name;

public:
    Student(int rollNo, const string& name) : rollNo(rollNo), name(name) {}

    void setName(const string& newName) { name = newName; }
    string getName() const { return name; }

    void print() const { cout << "Student -> Roll: " << rollNo << ", Name: " << name << '\n'; }
};

// 2) Inheritance + Runtime Polymorphism + Virtual Destructor
class Animal {
public:
    virtual ~Animal() { cout << "Animal destructor\n"; } // Important interview point
    virtual void sound() const { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    ~Dog() override { cout << "Dog destructor\n"; }
    void sound() const override { cout << "Dog barks\n"; }
};

// 3) Compile-time polymorphism (function overloading)
class Printer {
public:
    void show(int x) const { cout << "Int: " << x << '\n'; }
    void show(double x) const { cout << "Double: " << x << '\n'; }
};

// 4) Abstraction (abstract class)
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0; // pure virtual
};

class Rectangle : public Shape {
private:
    double l, w;

public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double area() const override { return l * w; }
};

// 5) Deep copy demo (Rule of 3 in short form)
class Buffer {
private:
    char* data;

public:
    explicit Buffer(const char* text) {
        size_t n = strlen(text);
        data = new char[n + 1];
        strcpy(data, text);
    }

    // Copy constructor (deep copy)
    Buffer(const Buffer& other) {
        size_t n = strlen(other.data);
        data = new char[n + 1];
        strcpy(data, other.data);
    }

    // Copy assignment (deep copy)
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        char* temp = new char[strlen(other.data) + 1];
        strcpy(temp, other.data);
        delete[] data;
        data = temp;
        return *this;
    }

    ~Buffer() { delete[] data; }

    void setFirstChar(char c) { data[0] = c; }
    const char* get() const { return data; }
};

// 6) static data member/function
class Counter {
private:
    static int count;

public:
    Counter() { ++count; }
    static int getCount() { return count; }
};
int Counter::count = 0;

// 7) friend function
class Box {
private:
    int value;

public:
    explicit Box(int value) : value(value) {}
    friend void printBoxValue(const Box& b);
};

void printBoxValue(const Box& b) { cout << "Box value: " << b.value << '\n'; }

// 8) Operator overloading
class Complex {
private:
    int real, imag;

public:
    Complex(int real, int imag) : real(real), imag(imag) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void print() const { cout << real << " + " << imag << "i\n"; }
};

int main() {
    cout << "=== OOPS Interview Important Concepts ===\n\n";

    cout << "[1] Class and Encapsulation\n";
    Student s(101, "Garv");
    s.print();
    s.setName("Garv Gupta");
    cout << "Updated name: " << s.getName() << "\n\n";

    cout << "[2] Inheritance + Runtime Polymorphism\n";
    Animal* a = new Dog();
    a->sound();
    delete a; // Dog then Animal destructor called because destructor virtual hai
    cout << '\n';

    cout << "[3] Compile-time Polymorphism (Overloading)\n";
    Printer p;
    p.show(7);
    p.show(7.5);
    cout << '\n';

    cout << "[4] Abstraction\n";
    Shape* sh = new Rectangle(10, 5);
    cout << "Rectangle area: " << sh->area() << '\n';
    delete sh;
    cout << '\n';

    cout << "[5] Deep Copy\n";
    Buffer b1("hello");
    Buffer b2 = b1;   // copy constructor
    b2.setFirstChar('y');
    cout << "b1: " << b1.get() << '\n';
    cout << "b2: " << b2.get() << '\n';
    cout << "(If deep copy works, b1 remains unchanged)\n\n";

    cout << "[6] Static Member\n";
    Counter c1, c2, c3;
    cout << "Counter objects created: " << Counter::getCount() << "\n\n";

    cout << "[7] Friend Function\n";
    Box b(42);
    printBoxValue(b);
    cout << '\n';

    cout << "[8] Operator Overloading\n";
    Complex cA(2, 3), cB(4, 5);
    Complex cC = cA + cB;
    cC.print();

    return 0;
}

