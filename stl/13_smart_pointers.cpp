#include <iostream>
#include <memory>
using namespace std;

class Node {
public:
    int value;
    explicit Node(int value) : value(value) {
        cout << "Node " << value << " created\n";
    }
    ~Node() { cout << "Node " << value << " destroyed\n"; }
};

int main() {
    // unique_ptr: single owner
    unique_ptr<Node> up = make_unique<Node>(10);
    cout << "unique_ptr value: " << up->value << '\n';

    // shared_ptr: multiple owners
    shared_ptr<Node> sp1 = make_shared<Node>(20);
    shared_ptr<Node> sp2 = sp1;
    cout << "shared_ptr use_count: " << sp1.use_count() << '\n';

    // weak_ptr: non-owning reference to shared_ptr object
    weak_ptr<Node> wp = sp1;
    if (auto locked = wp.lock()) {
        cout << "weak_ptr locked value: " << locked->value << '\n';
    }

    return 0;
}
