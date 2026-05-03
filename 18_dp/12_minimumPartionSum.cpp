#include<iostream>
#include<vector>
using namespace std;


int minSum(vector<int> ans){
    int totalSum = 0;

    for(int el: ans){
        totalSum += el;
    }
    //Caoacity
    int n = ans.size();
    int W = totalSum / 2;

    vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
    for(int i = 1; i < n+1; i++){
        for (int j = i; j < W+1; j++){
            if(ans[i-1] <= j){
                dp[i][j] = max(ans[i-1] + dp[i-1][j - ans[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1 = dp[n][W];
    int grp2Sum = totalSum - dp[n][W];

    return abs(grp2Sum - grp1);




}

int main(){ 
    vector<int>ans{11,5,5,1};

    return 0;

}