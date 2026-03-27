#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    // set: unique + sorted
    set<int> s = {4, 1, 3, 2, 2};
    cout << "set: ";
    for (int x : s) cout << x << " ";
    cout << '\n';

    // multiset: duplicates allowed + sorted
    multiset<int> ms = {1, 1, 2, 3, 3, 3};
    cout << "multiset count(3): " << ms.count(3) << '\n';

    // map: key-value, unique key, sorted by key
    map<string, int> marks;
    marks["Math"] = 95;
    marks["DSA"] = 98;
    marks["OOP"] = 90;

    cout << "map:\n";
    for (const auto& [key, value] : marks) {
        cout << key << " -> " << value << '\n';
    }

    // multimap: duplicate keys allowed
    multimap<string, int> mm;
    mm.insert({"A", 10});
    mm.insert({"A", 20});
    mm.insert({"B", 30});

    cout << "multimap entries for key A: ";
    auto range = mm.equal_range("A");
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << '\n';

    return 0;
}
