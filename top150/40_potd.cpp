#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        long long moves = 0;
        for (int x : nums) {
            moves += x - mn;
        }
        return moves;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1 - Expected: 3, Result: " << solution.minMoves(nums1) << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 1, 1};
    cout << "Test 2 - Expected: 0, Result: " << solution.minMoves(nums2) << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 1000000000};
    cout << "Test 3 - Expected: 999999999, Result: " << solution.minMoves(nums3) << endl;

    return 0;
}
