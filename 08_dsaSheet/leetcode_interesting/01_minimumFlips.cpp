#include<iostream>
using namespace std;

int maiFlips(string s){
    int n = s.length();

    // s = (s+s);  // replace this by s[j % n], so that it not goes out of bound eg: s = 11100; j = 5, n = 5 => 5 % 5 = 1;


    //s1 = "101010"
    //s2 = "010101"

    
    string s1, s2;
    for (int i  = 0; i < 2*n; i++){
        s1 += (i%2 ? '0' : '1');
        s2 += (i%2 ? '1' : '0');
    } 

    //sliding window
    int result = INT_MIN;
    int flip1 = 0;
    int flip2 = 0;

    int i = 0;
    int j = 0;

    while(j < 2* n){

        if (s[j%n]!= s1[j] ){
            flip1 ++;
        }
          if (s[j%n]!= s2[j]){
            flip2 ++;
        }
        if (j - 1 + 1 > n){// shrink the window form left
            if (s[j%n]!= s1[i]){
                flip1--;
            }
             if (s[j%n]!= s2[i]){
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

    return 0;
}