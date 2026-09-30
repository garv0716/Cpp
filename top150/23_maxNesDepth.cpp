#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution { 
public: 
    vector<int> maxDepthAfterSplit(string seq) { 
        int d = 0; 
        int n = seq.size(); 
        vector<int> res(n); 
        
        for(int i = 0; i < n; i++){ 
            if(seq[i] == '('){ 
                d++; 
                res[i] += (d % 2 == 0) ? 0 : 1; 
            } else { 
                res[i] += (d % 2 == 0) ? 0 : 1; 
                d--; 
            } 
        } 
        return res; 
    } 
};

int main() {
    Solution solver;
    
    // Test case: A valid parentheses string
    string seq = "(()())";
    
    // Call the function
    vector<int> result = solver.maxDepthAfterSplit(seq);
    
    // Print the output array
    cout << "Input sequence: " << seq << endl;
    cout << "Split results:  [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    
    return 0;
}
