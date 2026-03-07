#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;


/*
-----------------------------------------------------------
APPROACH 1 : No Rotation Allowed
-----------------------------------------------------------
Idea:
Only two possible alternating strings exist:

1) 010101...
2) 101010...

We count mismatches with both patterns
and return the minimum flips needed.

Time Complexity : O(n)
Space Complexity : O(1)
*/

int minFlips_NoRotation(string s){

    int n = s.length();

    int pattern1 = 0; // for pattern "010101"
    int pattern2 = 0; // for pattern "101010"

    for(int i = 0; i < n; i++){

        char expected1 = (i % 2 == 0) ? '0' : '1';
        char expected2 = (i % 2 == 0) ? '1' : '0';

        if(s[i] != expected1)
            pattern1++;

        if(s[i] != expected2)
            pattern2++;
    }

    return min(pattern1, pattern2);
}



/*
-----------------------------------------------------------
APPROACH 2 : Rotation Allowed (Using s + s)
-----------------------------------------------------------

Idea:
Since rotation is allowed, we simulate all rotations.

Example:
s = 11100

Rotations:
11100
11001
10011
00111
01110

Instead of generating rotations manually,
we concatenate:

s = s + s

Now every rotation becomes a substring of length n.

We use a sliding window of size n to check each rotation.

Time Complexity : O(n)
Space Complexity : O(n)
*/

int minFlips_UsingConcat(string s){

    int n = s.length();

    string ss = s + s;

    string pattern1 = "";
    string pattern2 = "";

    // create alternating patterns
    for(int i = 0; i < 2*n; i++){

        pattern1 += (i % 2) ? '1' : '0'; // 010101...
        pattern2 += (i % 2) ? '0' : '1'; // 101010...
    }

    int result = INT_MAX;

    int flip1 = 0;
    int flip2 = 0;

    int i = 0;

    for(int j = 0; j < 2*n; j++){

        if(ss[j] != pattern1[j])
            flip1++;

        if(ss[j] != pattern2[j])
            flip2++;

        // shrink window
        if(j - i + 1 > n){

            if(ss[i] != pattern1[i])
                flip1--;

            if(ss[i] != pattern2[i])
                flip2--;

            i++;
        }

        if(j - i + 1 == n)
            result = min(result, min(flip1, flip2));
    }

    return result;
}



/*
-----------------------------------------------------------
APPROACH 3 : Optimized Rotation (Using % n Trick)
-----------------------------------------------------------

Instead of creating s+s, we simulate circular access.

Example:

s = 11100
n = 5

j = 6
6 % 5 = 1

So s[6 % 5] = s[1]

This behaves exactly like accessing s+s.

Advantage:
No extra memory needed.

Time Complexity : O(n)
Space Complexity : O(1)
*/

int minFlips_Optimized(string s){

    int n = s.length();

    int result = INT_MAX;

    int flip1 = 0;
    int flip2 = 0;

    int i = 0, j = 0;

    while(j < 2*n){

        // expected characters for both alternating patterns
        char expected1 = (j % 2) ? '1' : '0';
        char expected2 = (j % 2) ? '0' : '1';

        if(s[j % n] != expected1)
            flip1++;

        if(s[j % n] != expected2)
            flip2++;

        // shrink sliding window
        if(j - i + 1 > n){

            expected1 = (i % 2) ? '1' : '0';
            expected2 = (i % 2) ? '0' : '1';

            if(s[i % n] != expected1)
                flip1--;

            if(s[i % n] != expected2)
                flip2--;

            i++;
        }

        if(j - i + 1 == n)
            result = min(result, min(flip1, flip2));

        j++;
    }

    return result;
}



/*
-----------------------------------------------------------
MAIN FUNCTION
-----------------------------------------------------------
*/

int main(){

    string s = "11100";

    cout << "Approach 1 (No Rotation): "
         << minFlips_NoRotation(s) << endl;

    cout << "Approach 2 (Using s+s): "
         << minFlips_UsingConcat(s) << endl;

    cout << "Approach 3 (Optimized % trick): "
         << minFlips_Optimized(s) << endl;

    return 0;
}