#include<iostream>
#include<vector>
using namespace std;

int change(vector<int>coins, int amount){
    int n = coins.size();

    //step 1 -> storage + meaning
    vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));

    // amount = 0 -> there is one way to include nothing.
    for(int i = 0; i < n+1; i++){
        dp[i][0] = 1;
    }
    //step 2 -> solve small problem
    for (int i = 1; i < n+1; i++){
        for(int j = 1; j < amount + 1; j++){
            if (coins[i-1] <= j){
                dp[i][j] = dp[i][j- coins[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (int i = 0; i < n+1; i++){
        for(int j = 0; j < amount + 1; j++){
            cout<< dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][amount];
}

int main(){

    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << change(coins, amount);

    return 0;
}