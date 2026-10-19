#include <iostream>
#include <vector>
#include <climits>  
#include <algorithm> 

using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
    int lo = 0;
    int sum = 0;
    int minLen = INT_MAX;
    
    for (int hi = 0; hi < nums.size(); hi++) {
        sum += nums[hi];
        
        while (sum >= target) {
            minLen = min(minLen, hi - lo + 1);
            sum -= nums[lo];
            lo++;
        }
    }
    
    return (minLen == INT_MAX) ? 0 : minLen;
}

int main() {

    int target1 = 7;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int result1 = minSubArrayLen(target1, nums1);
    cout << "Test Case 1 - Target: " << target1 << " | Result: " << result1 << " (Expected: 2)" << endl;


    int target2 = 4;
    vector<int> nums2 = {1, 4, 4};
    int result2 = minSubArrayLen(target2, nums2);
    cout << "Test Case 2 - Target: " << target2 << " | Result: " << result2 << " (Expected: 1)" << endl;


    int target3 = 11;
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int result3 = minSubArrayLen(target3, nums3);
    cout << "Test Case 3 - Target: " << target3 << " | Result: " << result3 << " (Expected: 0)" << endl;

    return 0;
}
