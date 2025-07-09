/*
Problem: Detect Cycle in a Directed Graph (DFS)
Link: https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph/
Approach: Convert edge list to adjacency list. Use DFS to visit all nodes.
Maintain two arrays — `vis` to mark visited nodes and `pathVis` to track the current DFS path.
If we revisit a node in the same DFS path (`pathVis[it] == 1`), a cycle is detected.
Reset pathVis on backtracking.
If a node is visited again in the same path (pathVis), a cycle exists.
Time: O(V + E), Space: O(2V)
Date: July 9, 2025
*/

class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj)) return true;
            }
            else if (pathVis[it]) return true;
        }

        pathVis[node] = 0;
        return false;
    }

  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> adj[V];

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return true;
            }
        }

        return false;
    }
};
