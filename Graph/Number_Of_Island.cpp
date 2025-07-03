/*
Problem: Number of Islands / Connected Components in a Binary Matrix
Link: https://www.geeksforgeeks.org/find-number-of-islands/
Approach: Use DFS to traverse each unexplored '1' and mark all connected land cells.
Time Complexity: O(n × m)
Space Complexity: O(n × n) for visited matrix and recursion stack
Date: July 3, 2025
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == '1') {
                dfs(nRow, nCol, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};
