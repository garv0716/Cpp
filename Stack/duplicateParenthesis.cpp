// #include<iostream>
// #include<stack>
// using namespace std;

// bool isDuplicate(string str){

//     stack<char> s;   // ✅ moved outside

//     for (int i = 0; i < str.length(); i++){
//         char ch = str[i];

//         if (ch != ')'){ 
//             s.push(ch);
//         }
//         else{

//             if (s.empty()) return false;  // safety check

//             if (s.top() == '('){
//                 return true; // duplicate
//             }

//             while (!s.empty() && s.top() != '('){
//                 s.pop();
//             }

//             if (!s.empty())
//                 s.pop();   // remove '('
//         }
//     }

//     return false;
// }

// int main (){
//     string str1 = "((a+b)()(a-b))";

//     if(isDuplicate(str1))
//         cout << "Duplicate Parenthesis Found\n";
//     else
//         cout << "No Duplicate Parenthesis\n";

//     return 0;
// }


#include<iostream>
#include<stack>
using namespace std;

bool isDuplicate(string str){
   stack<char> s;
   
   for (int i = 0; i < str.size(); i ++ ){
    char ch = str[i];
    if (ch != ')'){
        s.push(ch);
    }else {
        if (s.top() == '('){ // means top pe mil gaya
            return true;
        }
        while (s.top() != '('){
            s.pop();
        }
        s.pop(); // jab last mai opeaning aa gaya, toh lkast mai ek or bar pop.
    }

    return false;
   
  }
}

 int main () {
    string str1 = "((a+b)(a-b)))";
    if (isDuplicate){
    cout << "String contain duplicate" << endl;
    }else {
        cout<< "String does not contain duplicate" << endl;

    }
    return 0;
}