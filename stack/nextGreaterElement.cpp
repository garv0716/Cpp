#include<iostream>
using namespace std;

int main(){

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