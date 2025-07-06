/*
Problem: Detect Cycle in an Undirected Graph using BFS
Link: https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/
Approach: Use BFS with parent tracking to detect back-edges indicating a cycle.
Time: O(V + 2E), Space: O(V + 2E)
Where V = number of vertices, E = number of edges
Date: July 6, 2025
*/

class Solution {
  private:
    bool detect(int i, vector<int> adj[], int vis[]) {
        vis[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    q.push({it, node});
                    vis[it] = 1;
                }
                else if (parent != it) {
                    return true;
                }
            }
        }
        return false;
    }

  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};
