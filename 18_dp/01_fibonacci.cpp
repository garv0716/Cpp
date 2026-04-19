#include <iostream>
#include <vector>
using namespace std;

//Memoization 

int fiboDp(int n, vector<int>&f){ // O(n)

    //base case
    if (n == 0 || n == 1){
        return n;
    }
    // check if it present in our vec or not
    if(f[n] != -1){
        return f[n];
    }
    //work
    f[n] = fiboDp(n-1, f) + fiboDp(n-2, f);
    return f[n];
}

//tabulation

int fibTab(int n){
    //define ds
    vector<int> dp;
    //initialize smallest
    dp[0]=0;
    dp[1]=1;

    for (int i = 2; i < n; i++){
        dp[i] = dp[n-1] + dp[n-2];
    }
    return dp[n];
}


int main(){
    int n = 6;
    vector<int>f(n+1, -1);

    cout << fiboDp(n, f);

}