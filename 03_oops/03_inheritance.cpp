#include <iostream>
#include <string>
using namespace std;

/*
Topic: Inheritance
- Child class parent ke members inherit karti hai
*/

class Vehicle {
protected:
    string brand;

public:
    explicit Vehicle(const string& brand) : brand(brand) {}

    void showBrand() const {
        cout << "Brand: " << brand << '\n';
    }
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car(const string& brand, int seats) : Vehicle(brand), seats(seats) {}

    void showCarInfo() const {
        showBrand();
        cout << "Seats: " << seats << '\n';
    }
};

int main() {
    Car c1("Toyota", 5);
    c1.showCarInfo();
    return 0;
}
