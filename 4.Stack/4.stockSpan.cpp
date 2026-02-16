#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockSpan(vector<int>span, vector<int>ans){
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 0; i < stock.size(); i++){
        int currPrice = stock[i];

        while(!s.empty()){
            span[i] = i + 1;
        }else{
            int prevHigh = s.top();

        }
    }
}

int main(){
    vector<int>stock = {};
    vector<int>span = {0,0,0,0,0,0,0};
     return 0;
}

