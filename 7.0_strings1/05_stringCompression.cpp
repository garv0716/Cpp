#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int idx = 0;   // position where we write compressed characters

        for (int i = 0; i < n; i++){

            char ch = chars[i];   // current character
            int count = 0;        // count frequency of current character

            // count how many times this character repeats
            while (i < n && chars[i] == ch){
                count++;
                i++;
            }

            // if character occurs only once
            if (count == 1){
                chars[idx++] = ch;
            }
            else{

                // write the character
                chars[idx++] = ch;

                // convert count to string
                string str = to_string(count);

                // write digits of count
                for(char dig : str){
                    chars[idx++] = dig;
                }
            }

            // adjust because for loop will increment i
            i--;
        }

        // resize vector to compressed size
        chars.resize(idx);

        return idx;
    }
};


int main(){

    Solution obj;

    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = obj.compress(chars);

    cout << "Compressed Length: " << len << endl;

    cout << "Compressed Array: ";

    for(char c : chars){
        cout << c << " ";
    }

    cout << endl;

    return 0;
}



/*
========================================================
PROBLEM
========================================================

We are given a character array.

We must compress it using this rule:

If a character repeats k times:

char + k

Example:

[a,a,a,b,b,c]

Compressed result:

[a,3,b,2,c]

Return the new length.


========================================================
MAIN IDEA (VERY SIMPLE)
========================================================

We move through the array and count how many
times the current character repeats.

Then we write:

character + count

Example:

aaa -> a3
bb  -> b2
c   -> c


========================================================
IMPORTANT VARIABLES
========================================================

i
→ used to scan the original array

idx
→ where we store the compressed result

count
→ how many times a character repeats


========================================================
STEP BY STEP DRY RUN
========================================================

Example input:

[a,a,a,b,b,c,c,c]


------------------------------------
STEP 1
------------------------------------

i = 0

character = 'a'

Count how many 'a' appear:

a a a

count = 3


store in array:

a3

array becomes:

[a,3,_,_,_,_,_,_]

idx = 2


------------------------------------
STEP 2
------------------------------------

Now i moves to 'b'

b b

count = 2


store:

b2

array becomes:

[a,3,b,2,_,_,_,_]

idx = 4


------------------------------------
STEP 3
------------------------------------

Next character:

c c c

count = 3


store:

c3

array becomes:

[a,3,b,2,c,3,_,_]

idx = 6


------------------------------------
FINAL RESULT
------------------------------------

[a,3,b,2,c,3]

length = 6


========================================================
WHY WE USE to_string(count)?
========================================================

Because count can be more than 9.

Example:

aaaaaaaaaaaa

count = 12

We must store:

a12

So we convert number → string.


========================================================
WHY i-- ?
========================================================

Inside the while loop we already moved i forward.

But the for loop will again increase i.

So we do i-- to keep the correct position.


========================================================
TIME COMPLEXITY
========================================================

O(n)

Each character is visited once.


========================================================
SPACE COMPLEXITY
========================================================

O(1)

We modify the same array.


========================================================
INTERVIEW VARIATIONS
========================================================

1 String Compression II (Hard)

2 Run Length Encoding

3 Compress string and return new string

4 Decompress compressed string


=======================================================
KEY IDEA
========================================================

Count repeating characters and store:

character + frequency

Example:

aaaabbcc

→ a4b2c2
========================================================
*/