#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // begin / end
    auto it = v.begin();
    cout << "begin value: " << *it << '\n';

    // next / prev
    auto it2 = next(it, 2);   // points to 30
    auto it3 = prev(v.end()); // points to 50
    cout << "next(it,2): " << *it2 << '\n';
    cout << "prev(end): " << *it3 << '\n';

    // distance
    cout << "distance(begin, end): " << distance(v.begin(), v.end()) << '\n';

    // reverse iterators
    cout << "reverse traversal: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) cout << *rit << " ";
    cout << '\n';

    return 0;
}
