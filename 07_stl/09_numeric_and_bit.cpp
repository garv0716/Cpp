#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> v(5);
    iota(v.begin(), v.end(), 1); // 1 2 3 4 5

    cout << "iota: ";
    for (int x : v) cout << x << " ";
    cout << '\n';

    vector<int> ps(5);
    partial_sum(v.begin(), v.end(), ps.begin());
    cout << "partial_sum: ";
    for (int x : ps) cout << x << " ";
    cout << '\n';

    vector<int> diff(5);
    adjacent_difference(v.begin(), v.end(), diff.begin());
    cout << "adjacent_difference: ";
    for (int x : diff) cout << x << " ";
    cout << '\n';

    cout << "gcd(36, 48): " << gcd(36, 48) << '\n';
    cout << "lcm(12, 18): " << lcm(12, 18) << '\n';

    bitset<8> b(string("10110010"));
    cout << "bitset: " << b << '\n';
    cout << "count set bits: " << b.count() << '\n';
    cout << "flip bits: " << b.flip() << '\n';

    return 0;
}
