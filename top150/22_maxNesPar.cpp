#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (s[i] == ')') {
                count--;
            }
            maxdepth = max(maxdepth, count);
        }
        return maxdepth;
    }
};

int main() {
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    
    int result = sol.maxDepth(s);
    cout << "Maximum Depth: " << result << endl;
    
    return 0;
}
