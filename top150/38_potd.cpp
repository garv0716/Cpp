#include <vector>
#include <iostream>

using namespace std;

static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int r, int c) {
       
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 1) 
            return;
            
       
        grid[r][c] = 1;
        
       
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        
        
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) dfs(grid, i, 0);
            if (grid[i][n - 1] == 0) dfs(grid, i, n - 1);
        }
        
        
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 0) dfs(grid, 0, j);
            if (grid[m - 1][j] == 0) dfs(grid, m - 1, j);
        }
        
       
        int count = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j); 
                }
            }
        }
        
        return count;
    }
};

int main() {
    
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };

    Solution solver;
    int result = solver.closedIsland(grid);

    cout << "Total number of closed islands: " << result << endl;

    return 0;
}
