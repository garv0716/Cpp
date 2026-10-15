#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution { 
public: 
    int sumCounts(vector<int>& nums) { 
        int n = nums.size(), id{}; 
        int sum{}; 
        vector<int> fr(101); 
        
        for (int l = 0; l < n; l++) { 
            int cnt{}; 
            id++; 
            for (int r = l; r < n; r++) { 
                cnt += (fr[nums[r]] != id); 
                fr[nums[r]] = id; 
                sum += pow(cnt, 2); 
            } 
        } 
        return sum; 
    } 
};

int main() {
    
    Solution solution;
    
   
    vector<int> nums = {1, 2, 1};
    
    
    int result = solution.sumCounts(nums);
    
    cout << "The sum of counts is: " << result << endl;
    
    return 0;
}
