#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public: 

    // Function to check whether a character is alphanumeric
    bool isalnumCustom(char ch){
        if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s){
        int n = s.size();
        int st = 0;
        int end = n - 1;

        while (st < end){

            // Skip non-alphanumeric characters from the left
            if (!isalnumCustom(s[st])){
                st++;
                continue;
            }

            // Skip non-alphanumeric characters from the right
            else if (!isalnumCustom(s[end])){
                end--;
                continue;
            }

            // Compare characters ignoring case
            else if (tolower(s[st]) != tolower(s[end])){
                return false;
            }

            // Move both pointers
            st++;
            end--;
        }

        return true;
    }
};


int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (obj.isPalindrome(s)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }

    return 0;
}



/*
========================================================
PROBLEM
========================================================

Given a string s, determine if it is a palindrome after:

1. Ignoring non-alphanumeric characters
2. Ignoring case differences

Return true if it is a palindrome, otherwise return false.

Example:

Input:
"A man, a plan, a canal: Panama"

Output:
true

Explanation:
After removing non-alphanumeric characters and converting to lowercase:

amanaplanacanalpanama

This reads the same forward and backward.


========================================================
APPROACH (Two Pointer Technique)
========================================================

Instead of creating a new cleaned string, we process the
original string using two pointers.

Pointer 1 → st (start)
Pointer 2 → end (last index)

Steps:

1. Initialize
   st = 0
   end = n - 1

2. While st < end:

   a) If s[st] is not alphanumeric
      → move st++

   b) If s[end] is not alphanumeric
      → move end--

   c) If both are valid characters
      → compare them ignoring case

   d) If mismatch
      → return false

   e) Otherwise move both pointers inward


========================================================
WHY TWO POINTERS?
========================================================

Naive approach:

1. Remove non-alphanumeric characters
2. Convert to lowercase
3. Reverse the string
4. Compare with original

Time Complexity  : O(n)
Space Complexity : O(n)

Two pointer approach:

Time Complexity  : O(n)
Space Complexity : O(1)

Hence it is more optimal.


========================================================
IMPORTANT CONCEPTS
========================================================

1. tolower()

Converts uppercase letters to lowercase.

Example:
'A' → 'a'


2. Custom isalnum()

Checks if a character is:

- digit (0-9)
- alphabet (a-z)


3. continue

Skips the rest of the current loop iteration.


========================================================
DRY RUN
========================================================

Example:

s = "A man, a plan, a canal: Panama"

Initial:

A man, a plan, a canal: Panama
^                             ^
st                            end

Step 1:
Compare 'A' and 'a'

tolower → 'a' == 'a'

Step 2:
Skip spaces and punctuation.

Continue until st >= end.

Return true.


========================================================
TIME & SPACE COMPLEXITY
========================================================

Time Complexity:
O(n)

Each character is visited at most once.


Space Complexity:
O(1)

Only two pointers are used.


========================================================
INTERVIEW VARIATIONS
========================================================

1. Valid Palindrome II (LeetCode 680)

Allow deleting at most one character.

Example:
abca → true


2. Palindrome ignoring spaces only

Example:
"race car"


3. Palindrome Linked List


4. Longest Palindromic Substring


========================================================
COMMON INTERVIEW QUESTIONS
========================================================

Q1. Why not reverse the string?

Reversing requires O(n) extra space.

Two pointer approach uses O(1) space.


Q2. Can STL functions be used?

Yes:

isalnum()
tolower()

from <cctype>


Q3. What if string size is very large?

The algorithm still works efficiently because
it is linear time O(n).


========================================================
KEY TAKEAWAY
========================================================

This problem teaches:

- Two pointer technique
- String processing
- Case handling
- Character filtering

It is one of the most common interview warm-up problems.
========================================================
*/