/*
Problem: Rotting Oranges
Link: https://leetcode.com/problems/rotting-oranges/
Approach: Use multi-source BFS starting from all rotten oranges to track time to rot all fresh ones.
Time: O(N × M), Space: O(N × M)
Where N = number of rows, M = number of columns
Date: July 5, 2025
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        // {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        
        int ans = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans, t);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = r + dr[i];
                int nCol = c + dc[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==1 && vis[nRow][nCol] == 0) {
                    q.push({{nRow, nCol}, t+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};
