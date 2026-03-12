#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // Compare two frequency arrays
    bool isWindowSame(int freq1[], int freq2[]){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        // Store frequency of s1
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int idx = s1[i] - 'a';
            freq[idx]++;
        }

        // Create first window
        int windSz = s1.length();
        int windFreq[26] = {0};

        for(int i = 0; i < s2.length() && i < windSz; i++){
            int idx = s2[i] - 'a';
            windFreq[idx]++;
        }

        // Check first window
        if(isWindowSame(freq, windFreq)){
            return true;
        }

        // Slide the window
        for(int i = windSz; i < s2.length(); i++){

            // Remove left character
            windFreq[s2[i - windSz] - 'a']--;

            // Add new character
            windFreq[s2[i] - 'a']++;

            if(isWindowSame(freq, windFreq)){
                return true;
            }
        }

        return false;
    }
};


int main(){

    Solution obj;

    string s1, s2;

    cout << "Enter string s1: ";
    cin >> s1;

    cout << "Enter string s2: ";
    cin >> s2;

    if(obj.checkInclusion(s1, s2))
        cout << "Permutation of s1 exists in s2" << endl;
    else
        cout << "No permutation of s1 in s2" << endl;

    return 0;
}


/*
================================================
PROBLEM
================================================
Check if s2 contains a permutation of s1.

Example:
s1 = "ab"
s2 = "eidbaooo"

Output: true
because "ba" is a permutation of "ab"


================================================
APPROACH (Sliding Window)
================================================

1. Store frequency of characters in s1

2. Create a window in s2 of size s1.length()

3. Compare window frequency with s1 frequency

4. Slide window:
   - remove left character
   - add new right character

5. If frequencies match → permutation found


================================================
WHY THIS WORKS
================================================

A permutation must have the same character
frequency as s1.

So we compare frequency arrays of size 26.


================================================
COMPLEXITY
================================================

Time Complexity:
O(26 * n) ≈ O(n)

Space Complexity:
O(26) → constant


================================================
INTERVIEW VARIATIONS
================================================

1. Find all anagram indices in string
   (LeetCode 438)

2. Longest substring with k distinct chars

3. Minimum window substring

4. Sliding window maximum


================================================
KEY IDEA
================================================

Use Sliding Window + Frequency Count
to detect permutations efficiently.
================================================
*/