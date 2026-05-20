#include<iostream>
#include<vector>
using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int high = 0;
        int low = 0;
        int sum = 0;
        int result = INT_MAX;
        while(high < n){
            sum += nums[high];
            while(sum >= target){
                int len = high - low + 1;
                result = min(len, result);
                sum -= nums[low];
                low++;
            }
            high++;
        }
    return (result == INT_MAX) ? 0 : result;
}

int main(){
    vector<int>nums = {2,3,1,2,4,3};
    int target = 7;
    minSubArrayLen(target, nums);
    return 0;
}