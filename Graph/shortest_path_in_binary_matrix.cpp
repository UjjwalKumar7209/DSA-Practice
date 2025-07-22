// DATE: July 18, 2025
// PROBLEM: Shortest Path in Binary Matrix
// LINK: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// PLATFORM: LeetCode
// TAGS: Graph, BFS, Matrix
// LEVEL: Medium

// TIME COMPLEXITY: O(N * M * 8) ≈ O(N * M)
// SPACE COMPLEXITY: O(N * M) for dist matrix and queue
// (where N = number of rows, M = number of columns)

// APPROACH:
// - Classic BFS from top-left to bottom-right corner in 8 directions (including diagonals).
// - Each valid move must be within bounds and the cell should be 0 (i.e., not blocked).
// - We maintain a distance matrix to track shortest path length to each cell.
// - Start BFS with distance = 1 at (0, 0), and for each step, update neighbors if a shorter path is found.
// - If (n-1, m-1) remains unreachable (INT_MAX), return -1, else return dist[n-1][m-1].

class Solution {
private:
    bool isValid(int row, int col, int n, int m) {
        return (row >= 0 && col >= 0 && row < n && col < m);
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) return -1;
        if (n == 1 && m == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;

        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;

            for (int i = 0; i < 8; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if (isValid(nRow, nCol, n, m) && grid[nRow][nCol] == 0 && dis + 1 < dist[nRow][nCol]) {
                    dist[nRow][nCol] = dis + 1;
                    q.push({dis + 1, {nRow, nCol}});
                }
            }
        }

        return dist[n - 1][m - 1] == INT_MAX ? -1 : dist[n - 1][m - 1];
    }
};
