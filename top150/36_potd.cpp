#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int answer = -1; 
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                
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
    
   
    vector<int> nums = {0, 2, 1}; 
    
    int result = solution.sortPermutation(nums);
    cout << "Result: " << result << endl;
    
    return 0;
}
