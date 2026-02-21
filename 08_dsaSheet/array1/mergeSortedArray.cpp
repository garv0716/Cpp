
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



/*
===========================================================
QUESTION: Merge Two Sorted Arrays (In-place)
===========================================================

nums1 → size = m + n
        first m elements = valid sorted elements
        last n elements  = empty space (0)

nums2 → size = n
        contains sorted elements

Goal:
Merge nums2 into nums1 so that nums1 becomes fully sorted.

Example:
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]

Output:
nums1 = [1,2,2,3,5,6]

===========================================================
INTUITION:
===========================================================

We cannot merge from front,
because nums1 elements will get overwritten.

We merge from BACK because empty space exists there.

===========================================================
POINTERS USED:
===========================================================

i     → last valid element in nums1  → m-1
j     → last element in nums2        → n-1
index → last position of nums1       → m+n-1

===========================================================
WORKING:
===========================================================

Compare nums1[i] and nums2[j]

Put the larger element at nums1[index]

Move pointer of inserted element

Move index backward

Repeat until one array finishes

If nums2 still has elements → copy them

No need to copy nums1 elements

===========================================================
WHY THIS WORKS:
===========================================================

Because nums1 has extra space at end,
so filling from back prevents overwriting.

===========================================================
COMPLEXITY:
===========================================================

Time Complexity  → O(m+n)
Space Complexity → O(1)

===========================================================
*/
