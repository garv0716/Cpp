#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Create a 2D DP array with dimensions (n + 1) x (W + 1) initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table dp[i][w] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                // Max of including the current item or excluding it
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                // If weight of the current item is more than capacity w, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();

    cout << "Maximum value in knapsack = " << knapSack(W, wt, val, n) << endl;

    return 0;
}