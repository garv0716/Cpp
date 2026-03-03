#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    // array (fixed size)
    array<int, 4> arr = {10, 20, 30, 40};
    cout << "array front/back: " << arr.front() << " " << arr.back() << '\n';

    // vector (dynamic array)
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    cout << "vector: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    // deque (push/pop front and back fast)
    deque<int> dq = {2, 3};
    dq.push_front(1);
    dq.push_back(4);
    cout << "deque: ";
    for (int x : dq) cout << x << " ";
    cout << '\n';

    // list (doubly linked list)
    list<int> li = {1, 2, 4};
    auto it = li.begin();
    advance(it, 2);
    li.insert(it, 3);
    cout << "list: ";
    for (int x : li) cout << x << " ";
    cout << '\n';

    // forward_list (singly linked list)
    forward_list<int> fl = {2, 3, 4};
    fl.push_front(1);
    cout << "forward_list: ";
    for (int x : fl) cout << x << " ";
    cout << '\n';

    return 0;
}
