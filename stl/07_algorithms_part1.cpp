#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {7, 2, 9, 2, 5, 1};

    sort(v.begin(), v.end());
    cout << "sorted: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    cout << "binary_search(5): " << (binary_search(v.begin(), v.end(), 5) ? "true" : "false") << '\n';

    auto lb = lower_bound(v.begin(), v.end(), 2);
    auto ub = upper_bound(v.begin(), v.end(), 2);
    cout << "lower_bound(2) index: " << (lb - v.begin()) << '\n';
    cout << "upper_bound(2) index: " << (ub - v.begin()) << '\n';

    reverse(v.begin(), v.end());
    cout << "reversed: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    rotate(v.begin(), v.begin() + 2, v.end());
    cout << "rotated left by 2: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    cout << "sum: " << accumulate(v.begin(), v.end(), 0) << '\n';

    return 0;
}
