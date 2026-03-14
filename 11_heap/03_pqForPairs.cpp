#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// in class we do operator overloading inside the class
//in pairs we create a differernt struct and there we do operator overloading for the parenthesis

struct ComparePair{
    bool operator () (pair<string, int> &p1, pair<string,int> &p2){
        return p1.second < p2.second;
    }
};

int main(){
    // priority_queue<pair<string, int>>pq;// default heap for maxHeap
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;

    pq.push(make_pair("aman", 500));
    pq.push(make_pair("avanii", 1000));
    pq.push(make_pair("Monika", 2000));

    while (!pq.empty()){
        cout<< "Topper is : " << pq.top().first << "," << pq.top().second << endl;
        pq.pop();
    }

    return 0;
} 