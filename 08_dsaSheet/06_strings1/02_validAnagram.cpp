#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths differ, they cannot be anagrams
        if(s.size() != t.size())
            return false;

        int count[26] = {0};

        // Count characters of string s
        for(char c : s)
            count[c - 'a']++;

        // Subtract characters of string t
        for(char c : t)
            count[c - 'a']--;

        // Check if all counts return to zero
        for(int i = 0; i < 26; i++)
            if(count[i] != 0)
                return false;

        return true;
    }
};


int main() {

    Solution obj;

    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if(obj.isAnagram(s, t))
        cout << "Strings are Anagrams" << endl;
    else
        cout << "Strings are NOT Anagrams" << endl;

    return 0;
}


/*
================================================
PROBLEM
================================================
Check whether two strings are anagrams.

Two strings are anagrams if they contain the
same characters with the same frequency.

Example:
s = "anagram"
t = "nagaram"

Output: true


================================================
APPROACH
================================================
Use a frequency array of size 26.

Steps:
1. If lengths differ → return false
2. Count characters of s
3. Subtract characters of t
4. If any count != 0 → not an anagram


================================================
WHY THIS WORKS
================================================
For an anagram:

frequency(s) == frequency(t)

So after incrementing and decrementing,
all values must become 0.


================================================
COMPLEXITY
================================================
Time Complexity:  O(n)

Space Complexity: O(1)
(only 26 size array)


================================================
INTERVIEW VARIATIONS
================================================
1. Valid Anagram with uppercase letters
2. Anagram grouping (Group Anagrams)
3. Check anagram ignoring spaces
4. Unicode anagram check


================================================
KEY IDEA
================================================
Use frequency counting instead of sorting.

Sorting → O(n log n)
Frequency array → O(n)
================================================
*/