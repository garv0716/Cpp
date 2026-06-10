#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  // Function to calculate the minimum number of candies 
    int candy(vector<int>& ratings) {

        // Get number of children
        int n = ratings.size();

        // Initially give 1 candy to each child
        int candies = n;

        // Start from second child
        int i = 1;

        while (i < n) {

            // Skip equal ratings, no need to change candy count
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            // Initialize increasing slope counter
            int peak = 0;

            // Traverse strictly increasing ratings
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candies += peak;
                i++;
            }

            // Initialize decreasing slope counter
            int valley = 0;

            // Traverse strictly decreasing ratings
            while (i < n && ratings[i] < ratings[i - 1]) {
                valley++;
                candies += valley;
                i++;
            }

            // Remove extra candy given to peak (overlap of increasing and decreasing)
            candies -= min(peak, valley);
        }

        // Return total minimum candies required
        return candies;
    }
};
// Driver Code
int main() {

    // Create object of Solution class
    Solution sol;

    // Input array of ratings
    vector<int> ratings = {1, 3, 6, 8, 9, 5, 3};

    // Call function and print result
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;

    return 0;
}
