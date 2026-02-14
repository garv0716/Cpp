#include <iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &s, int val){
    if (s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp); 
}

int main (){
        stack<int> s;
        s.push(7);
        s.push(3);
        s.push(5);
        s.push(9);

        pushAtBottom(s, 10);

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    return 0;
}

/*
📌 Insert Element at Bottom of Stack (Using Recursion)

Goal:
Insert a value at the bottom of a stack
without using any extra data structure.

--------------------------------------------------
💡 IDEA:

Since stack follows LIFO,
we cannot directly access the bottom.

So we use recursion to:
1. Remove all elements until stack becomes empty.
2. Insert the new value.
3. Push back all removed elements in same order.

--------------------------------------------------
🧠 pushAtBottom(stack &s, int val)

Base Case:
If stack is empty:
    → push(val)
    → return

Recursive Case:
1. Store top element in temp
2. Pop it
3. Call pushAtBottom(s, val)
4. Push temp back

This ensures:
New value goes to bottom,
and previous elements remain in same order.

--------------------------------------------------
📊 Example:

Initial Stack (top → bottom):
9 5 3 7

After pushAtBottom(10):
9 5 3 7 10   (10 at bottom)

--------------------------------------------------
Time Complexity  : O(n)
Space Complexity : O(n)  (recursion stack)
*/
