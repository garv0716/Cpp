#include<iostream>
#include<stack>
using namespace std;

bool isDuplicate(string str){

    stack<char> s;   // ✅ moved outside

    for (int i = 0; i < str.length(); i++){
        char ch = str[i];

        if (ch != ')'){ 
            s.push(ch);
        }
        else{

            if (s.empty()) return false;  // safety check

            if (s.top() == '('){
                return true; // duplicate
            }

            while (!s.empty() && s.top() != '('){
                s.pop();
            }

            if (!s.empty())
                s.pop();   // remove '('
        }
    }

    return false;
}

int main (){
    string str1 = "((a+b)()(a-b))";

    if(isDuplicate(str1))
        cout << "Duplicate Parenthesis Found\n";
    else
        cout << "No Duplicate Parenthesis\n";

    return 0;
}
