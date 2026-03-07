#include<iostream>
#include<climits>

using namespace std;

int minFlips(string s){
    int n = s.length();

    // s = (s+s);  // replace this by s[j % n], so that it not goes out of bound eg: s = 11100; j = 5, n = 5 => 5 % 5 = 1;


    //s1 = "101010"
    //s2 = "010101"

    
    // string s1, s2;
    // for (int i  = 0; i < 2*n; i++){
    //     s1 += (i%2 ? '0' : '1');
    //     s2 += (i%2 ? '1' : '0');
    // } 

    //sliding window
    int result = INT_MAX;
    int flip1 = 0;
    int flip2 = 0;

    int i = 0;
    int j = 0;

    while(j < 2* n){
        char expectedCharS1 = (j%2) ? '1':'0';
        char expectedCharS2 = (j%2) ? '0':'1';

        if (s[j%n]!= expectedCharS1 ){
            flip1 ++;
        }
          if (s[j%n]!= expectedCharS2){
            flip2 ++;
        }
        if (j - 1 + 1 > n){// shrink the window form left
            expectedCharS1 = (i%2) ? '1':'0';
            expectedCharS2 = (i%2) ? '0':'1';

            if (s[i%n]!= expectedCharS1){
                flip1--;
            }
             if (s[i%n]!= expectedCharS2){
                flip2--;
            }
            i++;
        }
        if (j - i +1 == n){
            result = min({result, flip1, flip2});
        }
        j++;
    }
    return result;
}

int main (){
    string s = "11100";
    minFlips(s);

    return 0;
}