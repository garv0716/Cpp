#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        // Base case
        mp[0] = 1;
        
        int prefixSum = 0;
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            prefixSum += nums[i];
            
            // Check if (prefixSum - k) exists
            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }
            
            // Store current prefix sum
            mp[prefixSum]++;
        }
        
        return count;
    }
};

int main() {
    
    Solution obj;
    
    vector<int> nums = {1, 2, 1, 2};
    int k = 3;
    
    int ans = obj.subarraySum(nums, k);
    
    cout << "Total subarrays with sum " << k << " = " << ans << endl;
    
    return 0;
}