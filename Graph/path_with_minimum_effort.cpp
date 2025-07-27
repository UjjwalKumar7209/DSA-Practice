/*
LeetCode: https://leetcode.com/problems/path-with-minimum-effort/
Date: July 27, 2025

Problem:
Path With Minimum Effort

Approach:
- We apply Dijkstra’s algorithm on a 2D grid where each cell is a node.
- The "effort" to move between two adjacent cells is defined as the absolute height difference.
- Our goal is to minimize the maximum effort along the path from (0,0) to (n-1,m-1).
- We use a min-heap (priority queue) to always expand the path with the least current effort.
- A dist matrix keeps track of the minimum effort needed to reach each cell.
- We return the effort as soon as we reach the destination cell since Dijkstra guarantees it’s minimum.

Time Complexity: O(E log V)
Space Complexity: O(n * m * 4 * log(n*m)
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // {difference, {row, col}}
        priority_queue< 
        pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>> 
        > pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;

      
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n-1 && col == m-1) return diff;
            for (int i = 0; i < 4; i++) {
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                if (nRow>=0 && nRow<n && nCol>=0 && nCol<m) {
                    int effort = max(abs(heights[nRow][nCol] - heights[row][col]), diff);
                    if (effort < dist[nRow][nCol]) {
                        dist[nRow][nCol] = effort;
                        pq.push({effort, {nRow, nCol}});
                    }
                }
            }
        }
        return 0;
    }
};
