/*
Problem: Number of Enclaves
Link: https://www.geeksforgeeks.org/number-of-enclaves/
Approach: Perform DFS from all boundary 1s to mark reachable land. 
After that, count the number of 1s that are not visited (i.e., not connected to the boundary).
These unvisited land cells are enclosed completely.
Time: O(N × M), Space: O(N × M)
Where N = number of rows, M = number of columns
Date: July 7, 2025
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, vis, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse first and last row
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && grid[0][i] == 1) {
                dfs(0, i, vis, grid);
            }
            if (!vis[n-1][i] && grid[n-1][i] == 1) {
                dfs(n-1, i, vis, grid);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, vis, grid);
            }
            if (!vis[i][m-1] && grid[i][m-1] == 1) {
                dfs(i, m-1, vis, grid);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) cnt++;
            }
        }
        return cnt;
    }
};
