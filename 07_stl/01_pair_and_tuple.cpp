#include <iostream>
#include <tuple>
#include <utility>
using namespace std;

int main() {
    // pair syntax
    pair<int, string> p1 = {1, "Alice"};
    pair<int, string> p2 = make_pair(2, "Bob");

    cout << "Pair 1: " << p1.first << ", " << p1.second << '\n';
    cout << "Pair 2: " << p2.first << ", " << p2.second << '\n';

    // swap pairs
    swap(p1, p2);
    cout << "After swap, Pair 1: " << p1.first << ", " << p1.second << '\n';

    // tuple syntax
    tuple<int, string, double> t = {101, "Garv", 95.5};
    cout << "Tuple values: " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '\n';

    return 0;
}
