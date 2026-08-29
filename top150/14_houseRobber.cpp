#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(const vector<int>& nums) {
        int n = nums.size();
        
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // DP state tracking variable replacements for an entire array
        int prev2 = 0;       // Tracks max profit 2 houses back: dp[i-2]
        int prev1 = nums[0]; // Tracks max profit 1 house back: dp[i-1]
        
        for (int i = 1; i < n; ++i) {
            // Option 1: Rob the current house (nums[i] + profit from 2 houses back)
            // Option 2: Skip the current house (keep profit from 1 house back)
            int current = max(nums[i] + prev2, prev1);
            
            // Move state variables forward for the next iteration
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};

int main() {
    Solution solver;
    
    // Example 1: Standard street configuration
    vector<int> houses1 = {2, 7, 9, 3, 1};
    cout << "Test 1 - Houses: {2, 7, 9, 3, 1}" << endl;
    cout << "Maximum Loot: " << solver.rob(houses1) << " (Expected: 12)" << endl << endl;

    // Example 2: Alternating smaller/larger values
    vector<int> houses2 = {1, 2, 3, 1};
    cout << "Test 2 - Houses: {1, 2, 3, 1}" << endl;
    cout << "Maximum Loot: " << solver.rob(houses2) << " (Expected: 4)" << endl;

    return 0;
}
