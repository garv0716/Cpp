#include <iostream>
using namespace std;

/*
Topic: Abstraction
- Interface dikhate hain, implementation hide karte hain
- Abstract class + pure virtual function
*/

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0; // pure virtual
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double area() const override {
        return length * width;
    }
};

int main() {
    Shape* s = new Rectangle(10, 5);
    cout << "Area: " << s->area() << '\n';
    delete s;
    return 0;
}
