#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // map : signature -> list of anagrams
        unordered_map<string, vector<string>> mp;

        for(string str : strs){

            // frequency array for characters a-z
            vector<int> freq(26,0);

            // count frequency of characters
            for(char c : str){
                freq[c - 'a']++;
            }

            // convert frequency vector into a string key
            string key = "";

            for(int i = 0; i < 26; i++){
                key += to_string(freq[i]) + "#";
            }

            // store string in map using generated key
            mp[key].push_back(str);
        }

        // result container
        vector<vector<string>> ans;

        // extract grouped anagrams
        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }

 int main() {

    vector<string> strs{"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto group : ans){
        for(auto word : group){
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
========================================================
                GROUP ANAGRAMS - NOTES
========================================================

PROBLEM
-------
Given a list of strings, group the strings that are anagrams
of each other.

Example
-------
Input:
["eat","tea","tan","ate","nat","bat"]

Output:
[
 ["eat","tea","ate"],
 ["tan","nat"],
 ["bat"]
]


--------------------------------------------------------
WHAT IS AN ANAGRAM?
--------------------------------------------------------

Two strings are anagrams if:

• They contain the same characters
• Character frequency is identical

Example

eat -> e:1 a:1 t:1
tea -> t:1 e:1 a:1
ate -> a:1 t:1 e:1

All have the same frequency → anagrams


--------------------------------------------------------
CORE IDEA
--------------------------------------------------------

If two words are anagrams, their **character frequency
vector will be identical**.

Example

eat

[a b c d e f g ... t ... z]
[1 0 0 0 1 0 0 ... 1 ... 0]

tea

[a b c d e f g ... t ... z]
[1 0 0 0 1 0 0 ... 1 ... 0]

Same frequency → same group


--------------------------------------------------------
APPROACH
--------------------------------------------------------

1. Create a hashmap

unordered_map<string, vector<string>> mp

key   → frequency signature
value → list of anagrams


2. For every string

• create frequency array of size 26
• count characters


Example

str = "eat"

freq

[a,b,c,d,e,f,g,...t...]

[1,0,0,0,1,0,...,1]


3. Convert frequency into a string key

Example

"1#0#0#0#1#0#...#1#"


4. Insert string into hashmap

mp[key].push_back(str)


5. After processing all words

Extract values from hashmap


--------------------------------------------------------
WHY USE "#" IN KEY
--------------------------------------------------------

To avoid ambiguity.

Example

freq = [1,11]

Without separator

"111"

But this can also represent

[11,1]

Using separator

"1#11#"
"11#1#"

Both are different keys.


--------------------------------------------------------
DATA STRUCTURE USED
--------------------------------------------------------

unordered_map<string, vector<string>>

Example

key
"1#0#0#0#1#0#...#1#"

value
["eat","tea","ate"]


--------------------------------------------------------
DRY RUN
--------------------------------------------------------

Input

["eat","tea","tan","ate","nat","bat"]


Iteration 1
str = eat
key = K1
mp[K1] = ["eat"]


Iteration 2
str = tea
same key

mp[K1] = ["eat","tea"]


Iteration 3
str = tan
key = K2

mp[K2] = ["tan"]


Iteration 4
str = ate
same key

mp[K1] = ["eat","tea","ate"]


Iteration 5
str = nat

mp[K2] = ["tan","nat"]


Iteration 6
str = bat

mp[K3] = ["bat"]


Final groups

["eat","tea","ate"]
["tan","nat"]
["bat"]


--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------

n = number of strings
k = average string length

Frequency count = O(k)

Key creation = O(26) ≈ constant

Total

O(n * k)


--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------

O(n * k)

because we store all strings in hashmap.


--------------------------------------------------------
ALTERNATIVE APPROACH
--------------------------------------------------------

Sort the string.

Example

eat → aet
tea → aet
ate → aet

Use sorted string as key.

Code idea

sort(str.begin(), str.end())

Time Complexity

O(n * k log k)

Frequency approach is faster.


--------------------------------------------------------
IMPORTANT POINTS
--------------------------------------------------------

• Anagrams have identical character frequencies
• Frequency vector uniquely identifies an anagram group
• Convert frequency array into string to use as hashmap key
• "#" separator prevents ambiguity
• unordered_map groups strings efficiently

========================================================
*/ 