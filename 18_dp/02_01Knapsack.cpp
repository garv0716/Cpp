#include<iostream>
#include<vector>
using namespace std;

int knapS(vector<int> val, vector<int> wt, int W, int n){
    // base case
    if (n == 0 || W == 0){
        return 0;
    }
    int itemWt = wt[n-1];
    int itemval = val[n-1];
    //include
    if (itemWt <= W){
        // include
        int ans1 = knapS(val, wt, W - itemWt, n-1) + itemval;

        //exclude
        int ans2 = knapS(val, wt, W, n-1);
        return max(ans1, ans2);
        
    // exclude
    }else{
        return knapS(val, wt, W, n-1);
    }
}


// with Memoization

int knapMemo(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>>&dp){ //O(n * W)
    // base case
    if (n == 0 || W == 0){
        return 0;
    }
    if (dp[n][W] != -1){
        return dp[n][W];
    }

    int itemWt = wt[n-1];
    int itemval = val[n-1];
    //include
    if (itemWt <= W){
        // include
        int ans1 = knapMemo(val, wt, W - itemWt, n-1, dp) + itemval;
        //exclude
        int ans2 = knapMemo(val, wt, W, n-1, dp);
        dp[n][W] =  max(ans1, ans2);
    // exclude
    }else{
        dp[n][W] =  knapMemo(val, wt, W, n-1, dp);
    }
    return dp[n][W];
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2,5,1,3,4};
    int W = 7;
    int n = 5;
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout << knapMemo(val, wt, W, n, dp);
    return 0;
}
    
