#include<iostream>
#include<queue>
using namespace std;

void firstNonRepeat(string str){
        int n = str.size();
        queue<char>q;
        int freq [26] = {0};

        for(int i = 0; i < n; i++){
            int ch = str[i];
            freq[ch - 'a']++;
            q.push(ch);

            while(!q.empty() && freq[q.front() - 'a'] > 1 ){
                q.pop();
            }
        
        if (q.empty()){
            cout << "-1 " << endl;
        }else{
            cout << q.front() << endl;
        }

    }

}
int main(){

    string str = "aabccxb";
    firstNonRepeat(str);
    return 0;
}

/*
=> Apporach for first Non-Repeating Character in a Stream

Goal:
For every character in the string (stream),
print the first non-repeating character so far.
If none exists → print -1.

--------------------------------------------------
MAIN IDEA

We process characters one by one
and maintain:

1️ freq[26]  → stores frequency of each character
2️ queue<char> → stores potential non-repeating characters

Queue helps us track order of characters.

--------------------------------------------------
Algorithm

For each character:

1. Increase its frequency.
2. Push it into queue.
3. While:
      queue not empty AND
      front character frequency > 1
   → pop from queue

Why?
Because if frequency > 1,
it is no longer non-repeating.

4. After cleaning:
   - If queue empty → print -1
   - Else → print queue.front()
     (first non-repeating character)

--------------------------------------------------
Example: "aabccxb"

Step-by-step output:
a → a
a → -1
b → b
c → b
c → b
x → b
b → x

--------------------------------------------------
Time Complexity  : O(n)
(each character pushed and popped at most once)

Space Complexity : O(1)
(only 26 characters possible)

*/
