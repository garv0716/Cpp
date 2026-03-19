#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int largestSubWith0Sum(vector<int>arr){
    unordered_map<int, int> m;
    int sum = 0;
    int ans = 0;
    

    for (int j = 0; j < arr.size(); j++){
        sum += arr[j];

        if(m.count(sum)){
            int currLen = j - m[sum];
            ans = max(ans, currLen);
        }else{
            m[sum] = j;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 18};
    cout << "Max Subarray Length: " << largestSubWith0Sum(arr);
    return 0;

}

/*
========================================================
        LARGEST SUBARRAY WITH SUM = 0
========================================================

PROBLEM
-------
Given an array, find the **length of the longest subarray
whose sum is 0**.

Example

arr = [15, -2, 2, -8, 1, 7, 18]

Output → 5
Subarray → [-2, 2, -8, 1, 7]


--------------------------------------------------------
INTUITION (VERY IMPORTANT)
--------------------------------------------------------

Main idea is based on **prefix sum**.

We keep adding elements and track sum.

If the same sum appears again, it means:

- The elements in between sum to 0


Example

Index:   0   1   2   3
Array:  [1,  2, -2,  1]

Prefix sum

i=0 → 1
i=1 → 3
i=2 → 1  ← repeated sum!

So subarray (1 to 2) has sum = 0


--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

If prefix sum repeats:

sum(i) == sum(j)

Then subarray (i+1 to j) has sum = 0


--------------------------------------------------------
APPROACH
--------------------------------------------------------

1. Use unordered_map

map<sum, first_index>


2. Traverse array

sum += arr[j]


3. If sum already exists in map

→ subarray found

length = j - first_index


4. Update answer

ans = max(ans, length)


5. If sum not present

store it

m[sum] = j


--------------------------------------------------------
WHY STORE FIRST OCCURRENCE?
--------------------------------------------------------

We want **maximum length**.

So we keep earliest index of a sum.

Example

sum = 5 appears at index 2 and later at 6

length = 6 - 2 = 4 (maximum)


--------------------------------------------------------
DRY RUN
--------------------------------------------------------

arr = [15, -2, 2, -8, 1, 7, 18]

Step-by-step

j=0 → sum=15 → store (15,0)

j=1 → sum=13 → store (13,1)

j=2 → sum=15 → seen before at index 0  
length = 2 - 0 = 2

j=3 → sum=7 → store (7,3)

j=4 → sum=8 → store (8,4)

j=5 → sum=15 → seen at index 0  
length = 5 - 0 = 5 (max)

Final answer = 5


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

O(n)

Each element processed once.


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(n)

for hashmap storage.


--------------------------------------------------------
IMPORTANT POINTS
--------------------------------------------------------

• Use prefix sum concept  
• Same sum repeating ⇒ subarray sum = 0  
• Store first occurrence only  
• Works with negative numbers also  

========================================================
*/