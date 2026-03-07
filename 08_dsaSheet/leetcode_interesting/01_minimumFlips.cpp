#include<iostream>
#include<climits>

using namespace std;

int minFlips(string s){
    int n = s.length(); // length of original string

    // Using s[j % n] to simulate circular string instead of s = s + s

    int result = INT_MAX; // store minimum flips
    int flip1 = 0; // flips needed for pattern 010101...
    int flip2 = 0; // flips needed for pattern 101010...

    int i = 0; // window start
    int j = 0; // window end

    while(j < 2*n){ // iterate through virtual string of length 2n

        // expected chars for alternating patterns
        char expectedCharS1 = (j%2) ? '1' : '0';
        char expectedCharS2 = (j%2) ? '0' : '1';

        // compare current char with expected pattern
        if(s[j%n] != expectedCharS1) flip1++;
        if(s[j%n] != expectedCharS2) flip2++;

        // shrink window if size exceeds n
        if(j - i + 1 > n){
            expectedCharS1 = (i%2) ? '1' : '0';
            expectedCharS2 = (i%2) ? '0' : '1';

            if(s[i%n] != expectedCharS1) flip1--;
            if(s[i%n] != expectedCharS2) flip2--;

            i++;
        }

        // window size == n → one rotation checked
        if(j - i + 1 == n){
            result = min(result, min(flip1, flip2));
        }

        j++; // expand window
    }

    return result;
}

int main (){
    string s = "11100";
    cout << minFlips(s);

    return 0;
}