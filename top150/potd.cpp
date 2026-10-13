#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    static bool comparator(int a, int b) {
        return abs(a) > abs(b);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), comparator);
        
        int k = ceil(n / 2.0);
        long long positiveSum = 0, negativeSum = 0;
        
        for(int i = 0; i < n; i++) {
            // Note: Use long long for the square multiplication to prevent potential integer overflow
            long long square = (long long)nums[i] * nums[i]; 
            if(i < k) {
                positiveSum += square;
            } else {
                negativeSum += square;
            }
        }
        
        long long res = positiveSum - negativeSum;
        return res;
    }
};

int main() {
    Solution solver;

    // Test Case 1
    vector<int> nums1 = {4, 2, 5, 3};
    cout << "Test Case 1 Result: " << solver.maxAlternatingSum(nums1) << " (Expected: 44)" << endl;

    // Test Case 2
    vector<int> nums2 = {-1, -2, -3, -4, -5};
    cout << "Test Case 2 Result: " << solver.maxAlternatingSum(nums2) << " (Expected: 25)" << endl;

    return 0;
}
