/*
Problem: 01 Matrix (Nearest 1 in Binary Matrix)
Link: https://www.geeksforgeeks.org/0-1-matrix-find-distance-nearest-1-cell/
Approach: Push all cells with 1 into the queue and start BFS. From each 1, expand to adjacent 0s and assign them the 
shortest distance. This ensures every 0 gets the minimum distance to the nearest 1.
Time: O(N × M), Space: O(N × M)
Where N = number of rows, M = number of columns
Date: July 7, 2025
*/

class Solution {
  private:
    bool isValid(int row, int col, int n, int m) {
        if (row >= 0 && row < n && col >= 0 && col < m) return true;
        return false;
    }
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> dist(n, vector<int> (m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            for (int i = 0; i < 4; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if (isValid(nRow, nCol, n, m) && !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }
        }
        return dist;
    }
};
