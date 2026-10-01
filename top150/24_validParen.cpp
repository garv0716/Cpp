#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution { 
public: 
    bool isValid(string str) { 
        stack<char> s; 
        int n = str.size(); 
        
        if (n % 2 != 0) return false; 
        
        for (int i = 0; i < n; i++) { 
            char ch = str[i]; 
            if (ch == '(' || ch == '{' || ch == '[') { 
                s.push(ch); 
            } else { 
                if (s.empty()) return false; 
                char top = s.top(); 
                if ((top == '(' && ch == ')') || 
                    (top == '{' && ch == '}') || 
                    (top == '[' && ch == ']')) { 
                    s.pop(); 
                } else { 
                    return false; 
                } 
            } 
        } 
        return s.empty(); 
    } 
};

int main() {
    Solution solver;
    
    // Test cases
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "{([])}";
    
    cout << "Test 1 (\"" << test1 << "\"): " << (solver.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2 (\"" << test2 << "\"): " << (solver.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3 (\"" << test3 << "\"): " << (solver.isValid(test3) ? "Valid" : "Invalid") << endl;
    
    return 0;
}
