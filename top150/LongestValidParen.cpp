#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int resultLR = 0;
        int resultRL = 0;

        int n = s.length();

        // Left to right
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (close > open)
                open = close = 0;

            if (open == close)
                resultLR = max(resultLR, open + close);
        }

        // Right to left
        open = 0;
        close = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')')
                open++;
            else
                close++;

            if (close > open)
                open = close = 0;

            if (open == close)
                resultRL = max(resultRL, open + close);
        }

        return max(resultLR, resultRL);
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    cout << sol.longestValidParentheses(s) << endl;

    return 0;
}