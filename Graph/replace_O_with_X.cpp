/*
Problem: Replace all 'O' with 'X' (Surrounded Regions)
Link: https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/
Approach: Do DFS from all boundary 'O's to mark them and their connected components as visited. 
After that, all unvisited 'O's are surrounded by 'X' and hence should be flipped to 'X'.
Time: O(N × M), Space: O(N × M)
Where N = number of rows, M = number of columns
Date: July 7, 2025
*/

// User function Template for C++

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                !vis[nRow][nCol] && mat[nRow][nCol] == 'O') {
                dfs(nRow, nCol, vis, mat);
            }
        }
    }

  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse first and last row
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && mat[0][i] == 'O') {
                dfs(0, i, vis, mat);
            }
            if (!vis[n-1][i] && mat[n-1][i] == 'O') {
                dfs(n-1, i, vis, mat);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat);
            }
            if (!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat);
            }
        }

        // Replace all unvisited 'O's with 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};
