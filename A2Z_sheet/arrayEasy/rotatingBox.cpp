#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

    int m = boxGrid.size();
    int n = boxGrid[0].size();

    // Result matrix after rotation
    vector<vector<char>> result(n, vector<char>(m));

    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = boxGrid[j][i];
        }
    }

    // Reverse each row for 90-degree clockwise rotation
    for (vector<char>& row : result) {
        reverse(row.begin(), row.end());
    }

    // Apply gravity
    for (int col = 0; col < m; col++) {
        for (int i = n - 1; i >= 0; i--) {

            if (result[i][col] == '.') {

                int stoneRow = -1;

                for (int k = i - 1; k >= 0; k--) {

                    if (result[k][col] == '*') {
                        break;
                    }
                    else if (result[k][col] == '#') {
                        stoneRow = k;
                        break;
                    }
                }

                // Move stone down
                if (stoneRow != -1) {
                    result[i][col] = '#';
                    result[stoneRow][col] = '.';
                }
            }
        }
    }

    return result;
}

int main() {

    // Input box
    vector<vector<char>> boxGrid = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'}
    };

    // Function call
    vector<vector<char>> ans = rotateTheBox(boxGrid);

    // Output
    cout << "Rotated Box:\n";

    for (auto& row : ans) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}