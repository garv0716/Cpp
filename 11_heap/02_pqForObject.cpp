#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Student{ // "<" overloading
    public:
    string name;
    int marks;

    Student(string name, int marks){
        this->name = name;
        this ->marks = marks;
    }

    // in class objects we always need to do an operator overloading; if we need max Heap then we use '< ' in both place outer as well as inner, if we need an min Heap then we need to use '>' inside and '< ' outside also we mention the property through which we need to 
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
    }
};

int main(){
    //nhis priority queue stores the Student class object
    priority_queue<Student> pq;

    pq.push(Student("aman", 50));
    pq.push(Student("avanii", 65));
    pq.push(Student("Monika", 55));

    while (!pq.empty()){
        cout<< "Topper is : " << pq.top().name << "," << pq.top().marks << endl;
        pq.pop();
    }
    return 0;
}
