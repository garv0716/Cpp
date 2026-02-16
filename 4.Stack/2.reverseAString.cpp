#include <iostream>
#include <stack>
using namespace std;

void reverseString(string str){
    int n = str.length();
    string res = "";
    stack<char> s;
    for (int i = 0; i < n; i++){
        char ch = str[i];
        s.push (ch);
    }

    while(!s.empty()){
        res += s.top();
        s.pop();
    }

    cout << res;
}

int main(){
    string str1 = "hello";
    reverseString (str1);
    return 0;
}