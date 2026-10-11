#include <iostream>
#include <vector>

class Solution {
public:
    int sumOfSquares(std::vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 1; i <= nums.size(); i++) {
            if (n % i == 0) {
                res += nums[i - 1] * nums[i - 1];
            }
        }
        return res;
    }
};

int main() {
    // Example test case: indices 1-based (i = 1, 2, ... n)
    // If n = 4, divisors are 1, 2, 4 -> elements at index 0, 1, 3
    std::vector<int> nums = {1, 2, 3, 4};
    
    Solution solution;
    int result = solution.sumOfSquares(nums);
    
    std::cout << "Sum of squares: " << result << std::endl;
    return 0;
}
