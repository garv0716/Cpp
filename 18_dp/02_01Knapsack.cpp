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

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2,5,1,3,4};
    int W = 7;
    int n = 5;
    cout << knapS(val, wt, W, n);
    return 0;
}