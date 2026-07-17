#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = 0;

        // Prefix GCD calculation
        for (int &x : nums) {
            mx = max(mx, x);
            x = gcd(x, mx);
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Calculate GCD sum
        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n / 2; i++) {
            ans += gcd(nums[i], nums[n - 1 - i]);
        }

        return ans;
    }
};

int main() {
    int n;

    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.gcdSum(nums) << endl;

    return 0;
}