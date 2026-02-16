#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;

    public:
    void push(int data){ // O(n)
        while (!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
            q1.push(data);

            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
    }
    void pop(){
        q1.pop();
    }
    int top(){
        return q1.front();
    }
     bool empty(){
        return q1.empty();
    }
};

int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}


/*
=> Apporach for implement Stack using Two Queues 

Goal:
Implement stack (LIFO) behavior using queues (FIFO).

We use two queues:
    q1 → main queue
    q2 → helper queue

--------------------------------------------------
MAIN IDEA

To make stack behave like LIFO,
we make sure that the newest element
always stays at the front of q1.

So:
- push() becomes costly (O(n))
- pop() and top() become easy (O(1))

--------------------------------------------------
 push(int data)   → O(n)

Steps:
1. Move all elements from q1 → q2
2. Push new element into q1
3. Move everything back from q2 → q1

Result:
Newest element stays at front of q1
(simulating stack top)

--------------------------------------------------
 pop()   → O(1)

Simply remove front of q1
(because front = stack top)

--------------------------------------------------
 top()   → O(1)

Return q1.front()

--------------------------------------------------
 empty()

Return q1.empty()

--------------------------------------------------
Example

Push: 1, 2, 3, 4

q1 after pushes:
Front → 4 3 2 1

So stack order:
Top → 4 3 2 1

--------------------------------------------------
Time Complexity:
push  → O(n)
pop   → O(1)
top   → O(1)

Space Complexity:
O(n)

*/
