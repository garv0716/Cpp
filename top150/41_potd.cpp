#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 to enable binary search
        std::ranges::sort(arr2);
        
        // Push a sentinel value to avoid out-of-bounds when lower_bound returns the end iterator
        arr2.push_back(INT_MAX);
        
        int cnt = 0;
        for (int a : arr1) {
            // Find the first element in arr2 that is >= (a - d)
            // If that element is strictly greater than (a + d), it means 
            // there is no element in arr2 within the range [a - d, a + d]
            if (*std::ranges::lower_bound(arr2, a - d) > a + d) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;

    // Test Case 1
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;
    
    int result = solution.findTheDistanceValue(arr1, arr2, d);
    cout << "Distance Value: " << result << " (Expected: 2)" << endl;

    // Test Case 2
    vector<int> arr3 = {1, 4, 2, 3};
    vector<int> arr4 = {-4, -3, 6, 10, 20, 30};
    int d2 = 3;

    int result2 = solution.findTheDistanceValue(arr3, arr4, d2);
    cout << "Distance Value: " << result2 << " (Expected: 2)" << endl;

    return 0;
}
