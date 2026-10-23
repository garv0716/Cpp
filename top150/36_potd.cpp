#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int answer = -1; // Fixed: use integer -1 instead of string "-1;"
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                // If answer is still -1, initialize it; otherwise bitwise AND
                if (answer == -1) {
                    answer = nums[i];
                } else {
                    answer &= nums[i];
                }
            }
        }
        return answer == -1 ? 0 : answer;
    }
};

int main() {
    Solution solution;
    
    // Example test case
    vector<int> nums = {0, 2, 1}; // Modify test vector as needed
    
    int result = solution.sortPermutation(nums);
    cout << "Result: " << result << endl;
    
    return 0;
}
