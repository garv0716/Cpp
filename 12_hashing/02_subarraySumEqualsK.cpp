#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;


int subarrSumEqlK(vector<int> arr, int k){
    unordered_map<int , int> m;
    m[0] = 1;
    int sum = 0;
    int ans = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (m.count(sum-k)){
            ans += m[sum-k];
        }

        if (m.count(sum)){
            m[sum]++;
        }else{
            m[sum] = 1;
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << "Subarray Count = " << subarrSumEqlK(arr, k);
    return 0;
}
/*
========================================================
        COUNT SUBARRAYS WITH SUM = K
========================================================

PROBLEM
-------
Given an array and a value k, find the **number of
subarrays whose sum is equal to k**.

Example

arr = [10, 2, -2, -20, 10]
k = -10

Output → 3


--------------------------------------------------------
INTUITION (IMPORTANT)
--------------------------------------------------------

Use **prefix sum**.

We keep adding elements and track running sum.

If at any point:

sum - k exists before

👉 That means there is a subarray ending here
whose sum = k


--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

If

currentSum - previousSum = k

Then

previousSum = currentSum - k

So we check:

👉 Have we seen (sum - k) before?


--------------------------------------------------------
APPROACH
--------------------------------------------------------

1. Use unordered_map

map<sum, frequency>

This stores how many times a sum has appeared.


2. Initialize

m[0] = 1

Why?

To handle case where subarray starts from index 0.


3. Traverse array

sum += arr[i]


4. Check

if (sum - k exists)

→ add its frequency to answer

ans += m[sum - k]


5. Update map

m[sum]++


--------------------------------------------------------
WHY FREQUENCY?
--------------------------------------------------------

Because same sum can appear multiple times.

Each occurrence gives a valid subarray.


Example

If (sum-k) appeared 2 times

→ 2 subarrays end at current index


--------------------------------------------------------
DRY RUN
--------------------------------------------------------

arr = [10, 2, -2, -20, 10]
k = -10

Start

m = {0:1}
sum = 0


i=0 → sum=10  
check 10-(-10)=20 → not found  
m[10]=1


i=1 → sum=12  
check 12-(-10)=22 → not found  
m[12]=1


i=2 → sum=10  
check 10-(-10)=20 → not found  
m[10]=2


i=3 → sum=-10  
check -10-(-10)=0 → found (1 time)  
ans = 1  
m[-10]=1


i=4 → sum=0  
check 0-(-10)=10 → found (2 times)  
ans = 3  


Final Answer = 3


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

O(n)

Single traversal.


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(n)

for hashmap.


--------------------------------------------------------
IMPORTANT POINTS
--------------------------------------------------------

• Prefix sum + hashmap trick  
• Check (sum - k), not just sum  
• Store frequency, not index  
• m[0] = 1 is very important  
• Works with negative numbers  

========================================================
*/