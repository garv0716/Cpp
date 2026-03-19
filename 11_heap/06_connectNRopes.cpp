#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNropes(vector<int> &ropes){
    priority_queue<int, vector<int>, greater<int>>pq(ropes.begin(),ropes.end());
    int cost = 0;

    while (pq.size()> 1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();

        cost += (min1 + min2);
        pq.push(min1+min2);
    }
    cout << "min cost : " << cost;
    return cost;
}

int main(){
    vector<int> ropes = {4,3,2,6};
    connectNropes(ropes);
    return 0;

}

/*
========================================================
        CONNECT N ROPES WITH MINIMUM COST
========================================================

PROBLEM
-------
Given lengths of ropes, connect them into one rope.

Cost of connecting two ropes = sum of their lengths.

Goal:
👉 Minimize total cost of connecting all ropes.


Example

ropes = [4,3,2,6]

Output → 29


--------------------------------------------------------
INTUITION (IMPORTANT)
--------------------------------------------------------

Always connect the **two smallest ropes first**.

Why?

👉 Smaller ropes give smaller cost early
👉 Prevents large costs later


--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

Use **Min Heap** to always get smallest ropes.

Steps:

1. Pick 2 smallest ropes
2. Add their cost
3. Push new rope back
4. Repeat until one rope remains


--------------------------------------------------------
APPROACH
--------------------------------------------------------

1. Create Min Heap

priority_queue<int, vector<int>, greater<int>> pq


2. Insert all ropes


3. While size > 1

   • take smallest → min1  
   • take second smallest → min2  

   • cost += (min1 + min2)

   • push (min1 + min2) back into heap


4. Return total cost


--------------------------------------------------------
DRY RUN
--------------------------------------------------------

ropes = [4,3,2,6]

Min Heap

2 3 4 6


Step 1

2 + 3 = 5  
cost = 5  
Heap → 4 5 6


Step 2

4 + 5 = 9  
cost = 5 + 9 = 14  
Heap → 6 9


Step 3

6 + 9 = 15  
cost = 14 + 15 = 29  


Final Answer = 29


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

Heap operations → O(log n)

Total steps → n

Overall

O(n log n)


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(n)

for heap storage.


--------------------------------------------------------
IMPORTANT POINTS
--------------------------------------------------------

• Always pick 2 smallest elements  
• Use Min Heap (not max heap)  
• Greedy approach  
• Same logic used in **Huffman Coding**  

========================================================
*/