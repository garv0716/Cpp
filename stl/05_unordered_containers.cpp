#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    // unordered_set: unique, no order guarantee
    unordered_set<int> us = {5, 1, 5, 2, 3};
    cout << "unordered_set contains 2? " << (us.count(2) ? "yes" : "no") << '\n';

    // unordered_map: key-value hash table
    unordered_map<string, int> freq;
    freq["apple"]++;
    freq["banana"]++;
    freq["apple"]++;

    cout << "apple count: " << freq["apple"] << '\n';
    cout << "banana count: " << freq["banana"] << '\n';

    return 0;
}
