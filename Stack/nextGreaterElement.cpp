#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void nextGreater(vector<int>&arr , vector<int>&ans){
    int idx = arr.size() - 1;
    ans[idx] = -1;

    stack<int> s;
    s.push(arr[idx]);
    
    for (idx = idx - 1; idx >= 0; idx-- ) {   // we start treversing the elements from last 2nd element 

        int curr = arr[idx];
        while(!s.empty() && curr >= s.top()){   // jab tak stack khasli na hoo jayee
            s.pop();
        }
        if (s.empty()){
            ans[idx] = -1;
        } else{
            ans [idx] = s.top();
        }
        s.push(curr);
    }
    for (int i = 0; i < arr.size(); i++){
        cout << ans[i] << " ";
        cout << endl;
    }
}

int main(){

    vector <int> arr = {6,8,0,1,3};
    vector <int> ans = {0,0,0,0,0};
    nextGreater(arr,ans);

    return 0;
}

/*

=>Apporach

arr = [2,3,5,66,7,5,3,5]        ans = [5,-1]
- we travel backwards in our array
- make ans array of same size
- initialize value of last index with -1
- now we put element in stack form last and check weather the present is greater then arr[i], if yes then
   - we store top element of stack n our answer
   - and also push that arr[i] in the top of thr stack
- if the stack top element is < then the arr[i] then we do pop operation untill we found the greater element then arr[i]
   - if while doing pop operation out stack got empty then we puch '-1' in ans array, nd push arr[i] in stack 
   * we do not need the pop values if stack got empty

*/