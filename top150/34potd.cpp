#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        unordered_map<char, int> mp; 
        
        int lo = 0;
        int res = 0; 
        
        for (int high = 0; high < s.size(); high++) {
           
            if (mp.find(s[high]) != mp.end()) {
                
                lo = max(lo, mp[s[high]] + 1);
            }
     
            mp[s[high]] = high;
            
            res = max(res, high - lo + 1);
        }
        
        return res;
    }
};

int main() {
    Solution solver;
    

    string test1 = "abcabcbb";
    string test2 = "bbbbb";
    string test3 = "pwwkew";
    
    cout << "Length of longest substring for '" << test1 << "': " << solver.lengthOfLongestSubstring(test1) << " (Expected: 3)" << endl;
    cout << "Length of longest substring for '" << test2 << "': " << solver.lengthOfLongestSubstring(test2) << " (Expected: 1)" << endl;
    cout << "Length of longest substring for '" << test3 << "': " << solver.lengthOfLongestSubstring(test3) << " (Expected: 3)" << endl;
    
    return 0;
}
