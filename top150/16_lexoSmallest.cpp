#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] stores the latest index in word1 from where the suffix word2[j...m-1] can be formed
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        // Step 1: Precompute the rightmost valid indices for suffixes of word2
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        vector<int> ans;
        ans.reserve(m);

        bool canSkip = true;
        j = 0;

        // Step 2: Build the lexicographically smallest sequence greedily from the left
        for (i = 0; i < n && j < m; ++i) {
            // Case 1: The characters match perfectly
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                ++j;
            }
            // Case 2: Mismatch, but we are allowed to modify 1 character
            else if (canSkip && (j == m - 1 || (last[j + 1] != -1 && i < last[j + 1]))) {
                canSkip = false; // Consume our single modification permission
                ans.push_back(i);
                ++j;
            }
        }

        // If we matched all characters of word2, return the sequence indices
        if (j == m) {
            return ans;
        }

        // Otherwise, it's impossible to form a valid sequence
        return {};
    }
};

int main() {
    Solution solver;
    
    // Example test case
    string word1 = "abcde";
    string word2 = "adc";
    
    vector<int> result = solver.validSequence(word1, word2);
    
    cout << "Valid Sequence Indices: [";
    for (size_t k = 0; k < result.size(); ++k) {
        cout << result[k];
        if (k < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
