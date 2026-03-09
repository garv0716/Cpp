#include<iostream>
#include <vector>
using namespace std;

/*
NOTES: Trapping Rain Water (Prefix Max + Suffix Max)

Idea:
- Water above index i depends on the tallest wall on left and right.
- Possible water level at i = min(leftMax[i], rightMax[i]).
- Trapped water at i = waterLevel - height[i] (only if positive).

Why this works:
- Water cannot rise above the shorter boundary among left and right sides.

Complexity:
- Time: O(n)
- Space: O(n) for leftMax and rightMax
*/

   int waterTrap(vector<int>& height) {
        int n = height.size();
        int leftMax [20000];
        int rightMax  [20000];

        // Boundary initialization:
        // leftMax[0] has no left side, rightMax[n-1] has no right side.
        leftMax[0] = height[0];
        rightMax[n-1] = height[n-1];

        // Build prefix max array (excluding current bar in your implementation).
        for (int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        // Build suffix max array (excluding current bar in your implementation).
          for (int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }
        
        int waterTrapped = 0;
        // For each bar, add positive trapped water contribution.
        for (int i = 0; i < n; i++){
            int currWater = min(leftMax[i], rightMax[i]) - height[i];
            if  (currWater > 0){
                waterTrapped += currWater;
            }
        }
        return waterTrapped;
    }

int main(){
    // Example:
    // height = [4,2,0,3,2,5]
    // Output should be 9
    vector <int> height = {4,2,0,3,2,5};
    return 0;
}
