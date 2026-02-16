#include <iostream>
#include <stack>
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

void reverse(stack<int> &s){
    if (s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

void printStack(stack<int> s){   // pass copy
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(4);
    s.push(41);
    s.push(5);
    s.push(7);
    s.push(8);
    s.push(98);
    printStack(s);

    reverse(s);

    printStack(s);

    return 0;
}

/*
=> Reverse a Stack Using Recursion (No Extra Stack)

Goal:
Reverse the stack without using any extra data structure.
Only recursion + helper function.

--------------------------------------------------
 MAIN IDEA

To reverse a stack:
1. Remove the top element.
2. Recursively reverse the remaining stack.
3. Insert the removed element at the bottom.

We use a helper function: pushAtBottom()

--------------------------------------------------
pushAtBottom(stack &s, val)

Purpose:
Insert an element at the bottom of stack.

Logic:
- If stack empty → push(val)
- Else:
    store top in temp
    pop it
    call pushAtBottom(s, val)
    push temp back

--------------------------------------------------
 reverse(stack &s)

Logic:
- If stack empty → return
- Else:
    store top in temp
    pop it
    reverse remaining stack
    push temp at bottom

This reverses order completely.

--------------------------------------------------
printStack(stack s)

- Stack passed by value (copy)
- Prints without modifying original stack

--------------------------------------------------
 Example

Before reverse:
98 8 7 5 41 4  (top → bottom)

After reverse:
4 41 5 7 8 98

--------------------------------------------------
Time Complexity  : O(n²)
(Each pushAtBottom takes O(n) and called n times)

Space Complexity : O(n)
(recursion call stack)
*/
