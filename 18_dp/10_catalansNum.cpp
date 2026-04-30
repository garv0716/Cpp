#include <iostream>
using namespace std;

int catalan(int n){
    if (n == 0 || n == 1){
        return 1;
    }

    int ans = 0; 
    for(int i=0; i<n; i++){
        ans+= catalan(i) * catalan(n-i-1);
    }
    return ans;
}

int memoCatalan(int n, vector<int> &dp){
    if (n == 0 || n == 1){
        return 1;
    }
    if(dp[n]!= -1){
        return dp[n];
    }

    int ans = 0; 
    for(int i=0; i<n; i++){
        ans+= catalan(i) * catalan(n-i-1);
    }
    return dp[n] = ans;
}
int tabuCatalan(int n){ // O(n^2)
    vector<int>dp(n+1, 0);
    dp[0] = 1; 
    dp[1] = 1;
   

    for(int i = 2; i <=n; i++){ // here we pick ith catalan
        for (int j = 0; j < i; j++){ // 0 to i-1
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}


int main(){
    int n = 6;
    vector<int>dp(n+1, -1);

    for(int i = 0; i < n; i++){
        cout << tabuCatalan(i) <<  " ";
    }
    return 0;
}