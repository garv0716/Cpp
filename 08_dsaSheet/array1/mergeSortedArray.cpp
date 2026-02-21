
#include <bits/stdc++.h>
using namespace std;

// Function to merge nums2 into nums1 in-place using two pointers (from the back)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int size = m + n;
   int index = size - 1;	 // Position to insert at in nums1
   int i = m - 1;      	 // Last index of actual elements in nums1
   int j = n - 1;       	 // Last index of nums2


   // Merge both arrays starting from the back
   while (i >= 0 && j >= 0) {
       if (nums1[i] <= nums2[j]) {
           nums1[index--] = nums2[j--];
       } else {
           nums1[index--] = nums1[i--];
       }
   }

   // If any elements left in nums2, copy them over
   while (j >= 0) {
       nums1[index--] = nums2[j--];
   }
}


int main() {
   // Example input
   vector<int> nums1 = {1, 2, 3, 0, 0, 0};
   int m = 3;
   vector<int> nums2 = {2, 5, 6};
   int n = 3;


   // Call the optimized merge function
   merge(nums1, m, nums2, n);


   // Print the merged array
   cout << "Merged array: ";
   for (int num : nums1) {
       cout << num << " ";
   }
   cout << endl;


   return 0;
}
