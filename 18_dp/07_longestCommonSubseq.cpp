#include<iostream>
#include<vector>
using namespace std;

int lcs(string str1, string str2, vector<vector<int>>dp, int n, int m){ // O(n*m)

    if (str1.size() == 0 ||  str2.size() == 0){
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= m; j++){

        }
    }
}


int lcsTab(string str1, string str2, vector<vector<int>>dp, int n, int m){


     if (str1.size() == 0 ||  str2.size() == 0){
        return 0;
    }
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0 ));

    for(int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            if (str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];


}

int main(){

    string str1 = "abcdge";
    string str2 = "abedg";
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));


    return 0;
}