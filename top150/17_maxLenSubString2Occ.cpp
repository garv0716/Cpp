#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        uint64_t mask = 0;
        
        for (int l = 0, r = 0; r < s.length(); r++) {
            int k = (s[r] & 31) << 1;
            mask += 1ULL << k;
            
            while (((mask >> k) & 3) == 3) {
                mask -= 1ULL << ((s[l++] & 31) << 1);
            }
            
            res = max(res, r - l + 1);
        }
        
        return res;
    }
};

int main() {
    // Create an instance of your Solution class
    Solution solver;
    
    // Test Case 1
    string s1 = "bcbbbcba";
    cout << "Input: " << s1 << "\nOutput: " << solver.maximumLengthSubstring(s1) << endl;
    
    // Test Case 2
    string s2 = "aaaa";
    cout << "Input: " << s2 << "\nOutput: " << solver.maximumLengthSubstring(s2) << endl;

    return 0;
}
