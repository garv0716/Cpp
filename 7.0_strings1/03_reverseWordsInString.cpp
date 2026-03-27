#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s){
        int n = s.size();
        string ans = "";

        // Reverse entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++){
            string word = "";

            // Extract word
            while (i < n && s[i] != ' '){
                word += s[i];
                i++;
            }

            // Reverse the word to correct order
            reverse(word.begin(), word.end());

            // Add to answer if not empty
            if (word.length() > 0){
                ans += " " + word;
            }
        }

        // Remove first extra space
        return ans.substr(1);
    }
};


int main(){

    Solution obj;
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    cout << "Reversed words: " << obj.reverseWords(s) << endl;

    return 0;
}


/*
================================================
PROBLEM
================================================
Reverse the order of words in a string.

Example:
Input:  "the sky is blue"
Output: "blue is sky the"

Extra spaces should be removed.


================================================
APPROACH
================================================
1. Reverse the entire string
2. Extract each word
3. Reverse each word again
4. Add words to result string


Example:

Original:
"the sky is blue"

Step 1 (reverse whole string):
"eulb si yks eht"

Step 2 (reverse each word):
"blue is sky the"


================================================
WHY THIS WORKS
================================================
Reversing the entire string reverses word order.
Then reversing individual words restores them.


================================================
COMPLEXITY
================================================
Time Complexity:  O(n)

Space Complexity: O(n)


================================================
INTERVIEW VARIATIONS
================================================
1. Reverse words in-place
2. Reverse characters of each word
3. Reverse words without using extra string
4. Trim multiple spaces


================================================
KEY IDEA
================================================
Reverse entire string → reverse individual words.
================================================
*/