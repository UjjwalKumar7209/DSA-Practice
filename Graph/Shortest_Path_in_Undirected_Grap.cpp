/*
Problem: Shortest Path in Undirected Graph with Unit Weights  
Platform: GFG  
Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1  
Approach:
- Treat all edges as having weight 1 (unit weights).
- Use BFS to find the shortest path from the source node to all other nodes.
- Initialize all distances as infinity (1e9), and distance of source as 0.
- Traverse using BFS and update the distance if a shorter path is found.
- Return final distance array, replacing unreachable nodes with -1.
Time: O(N + E), Space: O(N)  
Date: July 16, 2025
*/

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        
        int dist[n];
        for (int i = 0; i < n; i++) dist[i] = 1e9;
        
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& it: adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    q.push(it);
                    dist[it] = dist[node] + 1;
                }
            }
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};
