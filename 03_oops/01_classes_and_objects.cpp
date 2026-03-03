#include <iostream>
#include <string>
using namespace std;

/*
Topic: Classes and Objects
- Class = blueprint
- Object = real instance of that blueprint
*/

class Student {
private:
    int rollNo;
    string name;

public:
    Student(int rollNo, const string& name) : rollNo(rollNo), name(name) {}

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << '\n';
    }
};

int main() {
    Student s1(101, "Garv"); // object created on stack
    s1.display();

    Student* s2 = new Student(102, "Aman"); // object created on heap
    s2->display();
    delete s2;

    return 0;
}
