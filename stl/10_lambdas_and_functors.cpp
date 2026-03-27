#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class DescendingComparator {
public:
    bool operator()(int a, int b) const { return a > b; }
};

int main() {
    vector<int> v = {4, 1, 7, 2, 9};

    // lambda: ascending
    sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
    cout << "sorted asc with lambda: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    // functor: descending
    sort(v.begin(), v.end(), DescendingComparator());
    cout << "sorted desc with functor: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    // capture example
    int limit = 5;
    int cnt = count_if(v.begin(), v.end(), [limit](int x) { return x > limit; });
    cout << "count > " << limit << ": " << cnt << '\n';

    // predefined function object
    cout << "greater<int>()(10, 7): " << greater<int>()(10, 7) << '\n';

    return 0;
}
