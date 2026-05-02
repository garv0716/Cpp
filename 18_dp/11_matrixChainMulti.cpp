#include<iostream>
#include<vector>
using namespace std;

int mcmRec(vector<int>arr, int i, int j){
    if (i == j){
        return 0;
    }
    int ans = INT_MAX;

    for(int k = i; i < j; k++){
        //(i, k)
        int cost1 = mcmRec(arr, i, k);
        //(k+1, j)
        int cost2 = mcmRec(arr, k+1, j);
        //curr partition cost 
        int currCost = cost1 + cost2 + arr[i-1] * arr[k] * arr[j];
        ans = min(ans, currCost);
    }

    return ans;
}

int mcmMem(vector<int>arr, vector<vector<int>>&dp, int i, int j){
    if (i == j){
        return 0;
    }
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;

     for(int k = i; i < j; k++){
        //(i, k)
        int cost1 = mcmMem(arr,dp,i, k);
        //(k+1, j)
        int cost2 = mcmMem(arr, dp, k+1, j);
        //curr partition cost 
        int currCost = cost1 + cost2 + arr[i-1] * arr[k] * arr[j];
        ans = min(ans, currCost);
    }
    return dp[i][j] = ans;
}

int main(){
    vector<int>arr = {1,2,3,4,3};
    int n = arr.size();
    vector<vector<int>>dp(n, vector<int>(n, -1));
    cout << mcmRec(arr, 1, n-1);
    cout<< mcmMem(arr, dp, 0, n-1);
    return 0;
}