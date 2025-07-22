/*
Problem: 1091. Shortest Path in Binary Matrix  
Platform: LeetCode  
Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/  
Approach:
- Use BFS to find the minimum steps from source to destination in a grid.
- Maintain a `dist` matrix initialized to ∞ (1e9), and set source distance to 0.
- Use a queue to traverse by layers: each move adds 1 to the step count.
- At each cell, explore its 4 neighbors; if traversable and the new distance is smaller, update it and enqueue.
- Return the distance once you reach the destination.
- If BFS finishes without reaching it, return -1.
Time: O(N × M), Space: O(N × M)
Date: July 22, 2025
*/

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if (source == destination) return 0;
        vector<vector<int>> dist(grid.size(), vector<int> (grid[0].size(), 1e9));
        int n = grid.size();
        int m = grid[0].size();
        dist[source.first][source.second] = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        queue<pair<int, pair<int, int>>> q;
        q.push({0 ,{source.first, source.second}});
        while (!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dt = q.front().first;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if (newRow>=0 && newRow<n && newCol>=0 && newCol<m &&
                    grid[newRow][newCol]!=0 && dt+1 < dist[newRow][newCol]) {
                        q.push({dt+1, {newRow, newCol}});
                        dist[newRow][newCol] = dt+1;
                        if (make_pair(newRow, newCol) == destination)
                            return dist[newRow][newCol];
                    }
            }
        }
        return -1;
    }
};
