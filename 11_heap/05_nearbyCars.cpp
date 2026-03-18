#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car {
    public:
       //we need to store the idx and the disSq 
       int idx;
       int disSq;

       Car(int idx, int disSq){
        this->idx = idx;
        this->disSq = disSq;
       }

       bool operator < (const Car &obj) const{
         return this->disSq > obj.disSq; // minheap
       }
};

void nearbyCar(vector<pair<int, int>> pos, int k){
    //Car object vector
    vector<Car> cars;

    for (int i = 0; i < pos.size(); i++){
        int disSq = (pos[i].first * pos[i].first) + (pos[i].second* pos[i].second);
        cars.push_back(Car(i, disSq));
    }
    priority_queue<Car>pq(cars.begin(), cars.end()); // O(n)
    for (int i = 0; i < k; i++){
       cout<< "car:" << pq.top().idx;
       pq.pop(); //O(klogn)
    }
}
 
int main(){
    vector <pair<int , int>> pos;
    pos.push_back(make_pair(3, 3));
    pos.push_back(make_pair(5, -1));
    pos.push_back(make_pair(-2, 4));
    int k = 2;

    nearbyCar(pos, k);

    return 0;
}

/*
========================================================
            K NEAREST CARS USING PRIORITY QUEUE
========================================================

PROBLEM
-------
Given positions of cars (x, y), find the **k cars closest
to the origin (0,0)**.

Distance formula

distance = √(x² + y²)

For comparison we use

distance² = x² + y²

because sqrt is unnecessary.


--------------------------------------------------------
KEY IDEA
--------------------------------------------------------

• Calculate distance² for every car
• Store (index, distance²)
• Use a **Min Heap**
• Extract k smallest distances


--------------------------------------------------------
CAR CLASS
--------------------------------------------------------

Stores:

idx   → car index
disSq → distance squared from origin

Example

Car(0, 18)
Car(1, 26)
Car(2, 20)


--------------------------------------------------------
CUSTOM COMPARATOR
--------------------------------------------------------

bool operator<(const Car &obj) const

This changes priority_queue behavior.

return this->disSq > obj.disSq

This makes the priority queue behave like a **Min Heap**.

Smallest distance appears at the top.


--------------------------------------------------------
ALGORITHM
--------------------------------------------------------

1. Iterate through all car positions

2. Compute distance

disSq = x² + y²

3. Store object

cars.push_back(Car(i, disSq))


4. Build priority queue

priority_queue<Car> pq(cars.begin(), cars.end())

Heap construction → O(n)


5. Extract k closest cars

Repeat k times

print pq.top()
pq.pop()


--------------------------------------------------------
DRY RUN
--------------------------------------------------------

Input

(3,3)   -> 3² + 3² = 18
(5,-1)  -> 5² + (-1)² = 26
(-2,4)  -> (-2)² + 4² = 20

Distances

Car0 -> 18
Car1 -> 26
Car2 -> 20

Min Heap

18
20
26

k = 2

Output

Car0
Car2


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

Distance calculation = O(n)

Heap build           = O(n)

k removals           = O(k log n)

Total

O(n + k log n)


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(n)

for storing car objects in heap.


--------------------------------------------------------
IMPORTANT POINTS
--------------------------------------------------------

• Distance squared avoids sqrt computation
• Custom comparator creates min heap
• priority_queue is max heap by default
• Used in many "K closest elements" problems

========================================================
*/