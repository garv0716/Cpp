#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6};

    cout << "count(6): " << count(v.begin(), v.end(), 6) << '\n';

    auto it = find(v.begin(), v.end(), 4);
    if (it != v.end()) cout << "4 found at index: " << (it - v.begin()) << '\n';

    cout << "all_of > 0? " << (all_of(v.begin(), v.end(), [](int x) { return x > 0; }) ? "yes" : "no") << '\n';
    cout << "any_of even? " << (any_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; }) ? "yes" : "no") << '\n';

    // remove-erase idiom
    v.erase(remove(v.begin(), v.end(), 6), v.end());
    cout << "after remove 6: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    vector<int> v2 = {5, 1, 5, 2, 5, 3, 4};
    nth_element(v2.begin(), v2.begin() + 3, v2.end());
    cout << "4th smallest element (0-index 3): " << v2[3] << '\n';

    partition(v2.begin(), v2.end(), [](int x) { return x % 2 == 0; });
    cout << "partitioned (even first): ";
    for (int x : v2) cout << x << " ";
    cout << '\n';

    string s = "aaabbbccc";
    cout << "is_sorted string? " << (is_sorted(s.begin(), s.end()) ? "yes" : "no") << '\n';

    return 0;
}
