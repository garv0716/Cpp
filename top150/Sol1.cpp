#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> applyGravity(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<string> res = grid;

    for (int j = 0; j < cols; ++j) {
        int cnt = 0;
        for (int i = 0; i < rows; ++i) {
            if (res[i][j] == '*') {
                cnt++;
                res[i][j] = '.';
            }
        }
        for (int i = rows - 1; i >= rows - cnt; --i) {
            res[i][j] = '*';
        }
    }
    return res;
}


vector<string> rotateRight(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<string> rotated(cols, string(rows, '.'));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[j][rows - 1 - i] = grid[i][j];
        }
    }
    return rotated;
}


vector<string> rotateLeft(const vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<string> rotated(cols, string(rows, '.'));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rotated[cols - 1 - j][i] = grid[i][j];
        }
    }
    return rotated;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<string> grid(m);
    for (int i = 0; i < m; ++i) {
        grid[i] = "";
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            grid[i] += ch;
        }
    }

    
    grid = applyGravity(grid);

    int k;
    cin >> k;
    for (int step = 0; step < k; ++step) {
        string dir;
        cin >> dir;
        if (dir == "right") {
            grid = rotateRight(grid);
        } else if (dir == "left") {
            grid = rotateLeft(grid);
        }
       
        grid = applyGravity(grid);
    }

   
    for (int i = 0; i < (int)grid.size(); ++i) {
        for (int j = 0; j < (int)grid[0].size(); ++j) {
            cout << grid[i][j] << (j == (int)grid[0].size() - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}