#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Row{
    public:
    int count;
    int idx;

    Row(int count, int idx){
        this->count = count;
        this->idx = idx;
    }
    bool operator < (const Row &obj) const{
        if (this->count == obj.count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};

void weakestSoilder(vector<vector<int>> matrix, int k){
    vector <Row> rows;

    for (int i = 0; i < matrix.size(); i++){
        int count = 0;
        for(int j = 0; j < matrix[i].size(); j++){
            count ++;
        }
        rows.push_back(Row(count, i));
    }
    priority_queue<Row> pq (rows.begin(), rows.end());

    for(int i = 0; i < k; i++){
        cout << "Row" << pq.top().idx << endl;
        pq.pop();
    }

}

int main(){
    vector<vector<int>> matrix = {
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}};
        weakestSoilder(matrix, 2);

    return 0;

}

/*
====================================================
        K WEAKEST ROWS (SOLDIERS) USING HEAP
====================================================

PROBLEM
-------
Given a binary matrix:

1 → soldier
0 → civilian

Each row is sorted (soldiers first, then civilians).

Find the **k weakest rows**.

Weakness rule:
1. Row with fewer soldiers is weaker
2. If soldiers equal → smaller row index is weaker


----------------------------------------------------
CORE IDEA
----------------------------------------------------

1. Count soldiers in each row
2. Store (soldierCount, rowIndex)
3. Use **Min Heap**
4. Extract k weakest rows


----------------------------------------------------
ROW CLASS
----------------------------------------------------

Stores:

count → number of soldiers
idx   → row index


Comparator

bool operator<(const Row &obj) const

Rules implemented:

1. Smaller soldier count → higher priority
2. If equal → smaller index first

Code logic:

if(count equal)
    return idx > obj.idx

else
    return count > obj.count

This makes priority_queue behave like **Min Heap**.


----------------------------------------------------
ALGORITHM
----------------------------------------------------

1. Traverse each row

2. Count soldiers

count++

3. Store row object

rows.push_back(Row(count, i))

4. Build heap

priority_queue<Row> pq(rows.begin(), rows.end())

5. Extract k weakest rows

repeat k times

print pq.top().idx
pq.pop()


----------------------------------------------------
EXAMPLE
----------------------------------------------------

Matrix

[1,0,0,0] → soldiers = 1
[1,1,1,1] → soldiers = 4
[1,0,0,0] → soldiers = 1
[1,0,0,0] → soldiers = 1


Stored

(1,0)
(4,1)
(1,2)
(1,3)


Heap order

(1,0)
(1,2)
(1,3)
(4,1)


k = 2

Output

Row0
Row2


----------------------------------------------------
TIME COMPLEXITY
----------------------------------------------------

Counting soldiers  → O(n * m)

Heap build         → O(n)

Remove k rows      → O(k log n)

Total

O(nm + k log n)


----------------------------------------------------
SPACE COMPLEXITY
----------------------------------------------------

O(n)

for storing row objects.


----------------------------------------------------
IMPORTANT
----------------------------------------------------

• priority_queue is max heap by default  
• custom comparator converts it to min heap  
• tie-breaker handled using row index  
• common problem: **K Weakest Rows in Matrix**

====================================================
*/