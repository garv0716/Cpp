#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};

        // Count numbers according to their remainder when divided by 3
        for (auto& s : stones)
            f[s % 3]++;

        // If the count of numbers divisible by 3 is even
        if (~f[0] & 1)
            return min(f[1], f[2]) >= 1;

        // If the count of numbers divisible by 3 is odd
        return abs(f[1] - f[2]) >= 3;
    }
};

int main() {
    Solution solution;

    int n;
    cin >> n;

    vector<int> stones(n);

    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    bool result = solution.stoneGameIX(stones);

    if (result)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}