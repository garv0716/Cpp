#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    // stack (LIFO)
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "stack top: " << st.top() << '\n';
    st.pop();
    cout << "stack top after pop: " << st.top() << '\n';

    // queue (FIFO)
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "queue front: " << q.front() << ", back: " << q.back() << '\n';
    q.pop();
    cout << "queue front after pop: " << q.front() << '\n';

    // priority_queue max heap
    priority_queue<int> maxHeap;
    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    cout << "maxHeap top: " << maxHeap.top() << '\n';

    // priority_queue min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);
    cout << "minHeap top: " << minHeap.top() << '\n';

    return 0;
}
