//Majority element [LC ]

// Approach
// Using Boyer-Moore Voting Algorithm

#include <bits/stdc++.h>
using namespace std;


// Solution class containing the majorityElement function
class Solution {
public:
   int majorityElement(vector<int>& nums) {
       int n = nums.size();
       int count = 1;
       int majority = nums[0];  // Assume the first element as majority candidate


       // Phase 1: Find a potential candidate using Moore’s Voting Algorithm
       for (int i = 1; i < n; i++) {
           if (nums[i] ==majority)
               count++;     // Same as candidate ? increase count
           else {
               count--;     // Different element ? decrease count
               if (count == 0) {
                   majority= nums[i];  // Change candidate
                   count = 1;
               }
           }
       }


       // Phase 2: Verify if the candidate is actually the majority

       count = 0;
       for (int i = 0; i < n; i++) {
           if (nums[i] == majority)
               count++;
       }
       // Check if it occurs more than n/2 times

       if (count > n / 2)
           return majority;
       else
           return -1;
   }
};

int main() {
   // Hardcoded array
   vector<int> nums = {2, 2, 1, 1, 2, 2, 2};


   // Create object and call the method
   Solution sol;
   int result = sol.majorityElement(nums);

   // Print result
   if (result != -1)
       cout << "Majority element is: " << result << endl;
   else
       cout << "No majority element found." << endl;


   return 0;
}
