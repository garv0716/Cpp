#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            char c = s[right];

            if(mp.find(c) != mp.end()) {
                left = max(left, mp[c] + 1);
            }

            mp[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }



    int main(){
        string s = "abcabcbb";
        lengthOfLongestSubstring(s);
    }



/*

PROBLEM:

Find length of longest substring without repeating characters.

APPROACH:
Use Sliding Window.

INTUITION:
If duplicate appears,
move left pointer just after previous occurrence.

WHAT:
Use unordered_map<char,int> to store last index.

HOW:
1. Use two pointers (left, right)
2. Expand right
3. If duplicate found:
      left = max(left, last_index + 1)
4. Update max length

WHY:
Ensures window always contains unique characters.

TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(256) or O(n)
    
*/