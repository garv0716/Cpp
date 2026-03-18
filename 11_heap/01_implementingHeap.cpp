#include<iostream>
#include<vector>
using namespace std;
class Heap {
    vector<int> vec;   // stores heap elements

public:

    // Insert element into heap (bubble up)
    void push(int val){
        vec.push_back(val);          // insert at end
        int child = vec.size() - 1;  // index of inserted element

        // move element up until heap property satisfied
        while(child > 0){
            int parent = (child - 1) / 2;

            if(vec[child] > vec[parent]){
                swap(vec[child], vec[parent]);
                child = parent;
            }
            else break;
        }
    }
    // Restore heap property (top -> down)
    void heapify(int i){
        int left = 2*i + 1;
        int right = 2*i + 2;

        int largest = i;

        if(left < vec.size() && vec[left] > vec[largest])
            largest = left;

        if(right < vec.size() && vec[right] > vec[largest])
            largest = right;

        if(largest != i){
            swap(vec[i], vec[largest]);
            heapify(largest);
        }
    }

    // Remove maximum element
    void pop(){
        if(vec.empty()) return;

        swap(vec[0], vec[vec.size()-1]); // move max to end
        vec.pop_back();                  // remove last element
        heapify(0);                      // restore heap
    }

    // Return maximum element
    int top(){
        return vec[0];
    }

    // Check if heap is empty
    bool empty(){
        return vec.size() == 0;
    }
};


int main(){

    Heap heap;

    heap.push(50);
    heap.push(10);
    heap.push(100);
    heap.push(30);
    heap.push(20);

    while(!heap.empty()){
        cout << "Top = " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}



/*
---------------------------
1. WHAT IS A HEAP?
---------------------------

Heap is a Complete Binary Tree (CBT) that satisfies the heap property.

Types of Heap:

1. Max Heap
   Parent >= Children

2. Min Heap
   Parent <= Children


Example Max Heap

        100
       /   \
     50     10
    /  \
   20   30


Important properties:

• It must be a Complete Binary Tree
• Usually implemented using array or vector
• Root always stores the maximum value in max heap


------------------------------------------------------------------


---------------------------
2. ARRAY REPRESENTATION
---------------------------

Instead of pointers, heap is stored in array/vector.

If node index = i

Left Child  = 2*i + 1
Right Child = 2*i + 2
Parent      = (i - 1) / 2


Example array

Index: 0   1   2   3   4
Value:100  50  10  20  30


Tree structure

        100
       /   \
     50     10
    /  \
   20   30


------------------------------------------------------------------


---------------------------
3. PUSH OPERATION
---------------------------

Goal:
Insert element while maintaining heap property.

Steps:

1 Insert element at the end of array

Example

Before insert

        50
       /
     10

Insert 100

        50
       /  \
     10   100


2 Compare child with parent

3 If child > parent → swap

4 Repeat until heap property satisfied


After fixing heap

        100
       /   \
     10     50


This process is called:

BUBBLE UP
or
UP-HEAP


Time Complexity

O(log n)


------------------------------------------------------------------


---------------------------
4. POP OPERATION
---------------------------

Goal:
Remove the maximum element.

Steps:

1 Swap root with last element

Before

        100
       /   \
     50     10

After swap

        10
       /   \
     50     100


2 Remove last element

        10
       /
     50


3 Restore heap using heapify

        50
       /
     10


This process is called

BUBBLE DOWN
or
DOWN-HEAP


Time Complexity

O(log n)


------------------------------------------------------------------


---------------------------
5. HEAPIFY FUNCTION
---------------------------

Heapify restores heap property starting from a node.

Algorithm

1 Find left child
2 Find right child
3 Find largest among parent, left, right
4 Swap parent with largest child
5 Recursively call heapify


Example

Parent = 10
Left   = 50
Right  = 20

Largest = 50

Swap

        50
       /
     10


------------------------------------------------------------------


---------------------------
6. TIME COMPLEXITY
---------------------------

push()      -> O(log n)
pop()       -> O(log n)
heapify()   -> O(log n)
top()       -> O(1)


------------------------------------------------------------------


---------------------------
7. SPACE COMPLEXITY
---------------------------

O(n)

because heap stores n elements.


------------------------------------------------------------------


---------------------------
8. COMMON USES OF HEAP
---------------------------

Heaps are heavily used in many algorithms.

Examples

• Priority Queue
• Heap Sort
• Dijkstra Algorithm
• Prim's Algorithm
• Kth Largest Element
• Top K Frequent Elements
• Median of Data Stream


------------------------------------------------------------------


---------------------------
9. STL EQUIVALENT
---------------------------

C++ provides heap implementation using priority_queue.

Example

priority_queue<int> pq;

pq.push(10);
pq.push(50);
pq.push(100);

cout << pq.top();   // 100


Time Complexity

push -> O(log n)
pop  -> O(log n)
top  -> O(1)


------------------------------------------------------------------


---------------------------
10. IMPORTANT INTERVIEW POINTS
---------------------------

Always remember:

Insert  → Bubble Up
Delete  → Bubble Down

Heap is always stored as Complete Binary Tree.

Root of Max Heap always stores largest element.


======================================================================
*/