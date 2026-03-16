#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void slidingWindowMax(vector<int>arr, int k){
    priority_queue<pair<int, int>> pq;
    //first window
    for (int i = 0; i < k; i++){
        pq.push(make_pair(arr[i], i));
    }
    cout << "output: "<< pq.top().first<< " ";
    for (int i = k; i < arr.size(); i++ ){
        while(!pq.empty() && pq.top().second <=(i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr[i], i));
        cout << pq.top().first<< " ";
    }
}

int main(){
    vector <int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    slidingWindowMax(arr, k);
    return 0;
}
/*
====================================================
        SLIDING WINDOW MAXIMUM USING HEAP
====================================================

PROBLEM
-------
Given an array and window size k, find the **maximum
element in every sliding window** of size k.

Example

arr = [1,3,-1,-3,5,3,6,7]
k = 3

Windows

[1,3,-1] → 3
[3,-1,-3] → 3
[-1,-3,5] → 5
[-3,5,3] → 5
[5,3,6] → 6
[3,6,7] → 7

Output

3 3 5 5 6 7


----------------------------------------------------
CORE IDEA
----------------------------------------------------

Use **Max Heap (priority_queue)**.

Store:

(value, index)

Why index?

To remove elements that go **out of the window**.


----------------------------------------------------
ALGORITHM
----------------------------------------------------

1. Insert first k elements into heap.

2. The top of heap = maximum of first window.

3. For every new element:

   a) Remove elements whose index is outside window

      pq.top().second <= (i - k)

   b) Insert new element

   c) Top of heap = maximum of current window


----------------------------------------------------
DATA STORED IN HEAP
----------------------------------------------------

pair<int,int>

first  → element value  
second → index


Example entry

(5,4)

value = 5  
index = 4


----------------------------------------------------
DRY RUN
----------------------------------------------------

Array

[1,3,-1,-3,5,3,6,7]
k = 3


First window

push

(1,0)
(3,1)
(-1,2)

Heap top → 3

Output → 3


Next window

i = 3

remove elements outside window

index <= 0

push (-3,3)

Heap top → 3

Output → 3


Continue same process.


Final output

3 3 5 5 6 7


----------------------------------------------------
TIME COMPLEXITY
----------------------------------------------------

Each push/pop → O(log n)

Total operations ≈ n

Time

O(n log n)


----------------------------------------------------
SPACE COMPLEXITY
----------------------------------------------------

O(n)

for heap storage.


----------------------------------------------------
IMPORTANT POINTS
----------------------------------------------------

• priority_queue is **Max Heap by default**

• Store **index to track window validity**

• Remove outdated elements before computing max

• Common problem: **Sliding Window Maximum**

====================================================
*/