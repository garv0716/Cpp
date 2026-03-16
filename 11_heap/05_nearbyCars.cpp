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