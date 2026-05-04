#include<iostream>
#include<vector>
using namespace std;

void setZeros(vector<vector<int>> &mat){
    int n = mat.size();
    int m = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (mat[i][j] == 0){
                for(int col = 0; col < m; col++){
                    if (mat[i][col] != 0){
                        mat[i][col] = -1;
                    }
                }
                for(int row = 0; row < n; row++){
                    if (mat[row][j] != 0){
                        mat[row][j] = -1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};

    // Call function to modify matrix
    setZeros(mat);
    
    // Print final matrix
    for (auto row : mat) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}