#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int prev2 = 1; // ways to reach (i-2)th step
        int prev1 = 2; // ways to reach (i-1)th step
        int current = 0;

        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    int n = 5;
    std::cout << "Distinct ways to climb " << n << " steps: " 
              << sol.climbStairs(n) << std::endl;
    return 0;
}
