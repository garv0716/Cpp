#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

    bool validSub(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;

        for(int row = sr; row <= er; row++) {
            for(int col = sc; col <= ec; col++) {
                char ch = board[row][col];

                if(ch == '.') continue;

                if(st.count(ch))
                    return false;

                st.insert(ch);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // Validate rows
        for(int row = 0; row < 9; row++) {
            unordered_set<char> st;

            for(int col = 0; col < 9; col++) {
                char ch = board[row][col];

                if(ch == '.') continue;

                if(st.count(ch))
                    return false;

                st.insert(ch);
            }
        }

        // Validate columns
        for(int col = 0; col < 9; col++) {
            unordered_set<char> st;

            for(int row = 0; row < 9; row++) {
                char ch = board[row][col];

                if(ch == '.') continue;

                if(st.count(ch))
                    return false;

                st.insert(ch);
            }
        }

        // Validate 3x3 boxes
        for(int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;

            for(int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;

                if(!validSub(board, sr, er, sc, ec))
                    return false;
            }
        }

        return true;
    }
};

int main() {

    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku Board (9x9)\n";
    cout << "Use digits 1-9 and '.' for empty cells:\n";

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;

    if(obj.isValidSudoku(board))
        cout << "Valid Sudoku\n";
    else
        cout << "Invalid Sudoku\n";

    return 0;
}