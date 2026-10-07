#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        return F(s, 0, s.length());
    }

private:
    int F(const string& s, int i, int j) {
        int ans = 0, bal = 0;
        for (int k = i; k < j; ++k) {
            bal += (s[k] == '(' ? 1 : -1);
            if (bal == 0) {
                if (k - i == 1) {
                    ans++;
                } else {
                    ans += 2 * F(s, i + 1, k);
                }
                i = k + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    
    // Test cases
    string test1 = "()";
    string test2 = "(())";
    string test3 = "()()";
    string test4 = "(()(()))";
    
    cout << "Score of \"" << test1 << "\": " << solver.scoreOfParentheses(test1) << " (Expected: 1)" << endl;
    cout << "Score of \"" << test2 << "\": " << solver.scoreName(test2) << " (Expected: 2)" << endl;
    cout << "Score of \"" << test3 << "\": " << solver.scoreOfParentheses(test3) << " (Expected: 2)" << endl;
    cout << "Score of \"" << test4 << "\": " << solver.scoreOfParentheses(test4) << " (Expected: 6)" << endl;
    
    return 0;
}
