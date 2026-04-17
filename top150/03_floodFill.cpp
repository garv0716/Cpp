#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void dfs(int row, int col, int n, int m,
             vector<vector<bool>>& vis,
             vector<vector<int>>& image,
             int newColor,
             int oldColor)
    {
        vis[row][col] = true;
        image[row][col] = newColor;

        // up
        if (row - 1 >= 0 && !vis[row - 1][col] &&
            image[row - 1][col] == oldColor)
        {
            dfs(row - 1, col, n, m, vis, image, newColor, oldColor);
        }

        // down
        if (row + 1 < n && !vis[row + 1][col] &&
            image[row + 1][col] == oldColor)
        {
            dfs(row + 1, col, n, m, vis, image, newColor, oldColor);
        }

        // right
        if (col + 1 < m && !vis[row][col + 1] &&
            image[row][col + 1] == oldColor)
        {
            dfs(row, col + 1, n, m, vis, image, newColor, oldColor);
        }

        // left
        if (col - 1 >= 0 && !vis[row][col - 1] &&
            image[row][col - 1] == oldColor)
        {
            dfs(row, col - 1, n, m, vis, image, newColor, oldColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        int oldColor = image[sr][sc];

        // Important optimization
        if (oldColor == newColor)
            return image;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(sr, sc, n, m, vis, image, newColor, oldColor);

        return image;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    vector<vector<int>> result =
        obj.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (auto &row : result) {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
