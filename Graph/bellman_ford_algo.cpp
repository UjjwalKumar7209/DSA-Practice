/*
Problem: Bellman-Ford Algorithm
Link: https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/
Approach: Initialize distances with a large value. Perform V-1 edge relaxations.
          Then, perform one more iteration to check for a negative weight cycle.
Time: O(V * E), Space: O(V)
Where V = number of vertices, E = number of edges
Date: July 30, 2025
*/

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        // TC -> V*E;
        
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V-1; i++) {
            for (auto& it: edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Nth relaxation to check if there is negative cycle
        for (auto& it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};
