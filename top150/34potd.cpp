#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character
        unordered_map<char, int> mp; 
        
        int lo = 0;
        int res = 0; // Length cannot be negative, initialized to 0
        
        for (int high = 0; high < s.size(); high++) {
            // If the character is already in the map and within the current window
            if (mp.find(s[high]) != mp.end()) {
                // Move the lower bound of the window to the right of the duplicate's last position
                lo = max(lo, mp[s[high]] + 1);
            }
            
            // Record or update the current position of the character
            mp[s[high]] = high;
            
            // Calculate the window size and update max length
            res = max(res, high - lo + 1);
        }
        
        return res;
    }
};

int main() {
    Solution solver;
    
    // Test cases
    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";
    
    cout << "Length of longest substring for '" << test1 << "': " << solver.lengthOfLongestSubstring(test1) << " (Expected: 3)" << endl;
    cout << "Length of longest substring for '" << test2 << "': " << solver.lengthOfLongestSubstring(test2) << " (Expected: 1)" << endl;
    cout << "Length of longest substring for '" << test3 << "': " << solver.lengthOfLongestSubstring(test3) << " (Expected: 3)" << endl;
    
    return 0;
}
