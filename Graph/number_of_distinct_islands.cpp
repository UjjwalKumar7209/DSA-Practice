/*
Problem: Number of Distinct Islands
Link: https://www.geeksforgeeks.org/find-number-of-distinct-islands/
Approach: Use DFS to traverse each island and store its shape (relative coordinates from base cell).
By using a set to store unique island shapes, we count how many distinct patterns exist.
Time: O(N × M), Space: O(N × M)
Where N = number of rows, M = number of columns
Date: July 8, 2025
*/

class Solution {
  private:
    void dfs(int row, int col, vector<pair<int, int>>& vec, vector<vector<int>>& vis, vector<vector<int>>& grid, int baseRow, int baseCol) {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row - baseRow, col - baseCol});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, vec, vis, grid, baseRow, baseCol);
            }
        }
    }

  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vec, vis, grid, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size(); 
    }
};
