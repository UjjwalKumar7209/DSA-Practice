/*
Problem: Check if Graph is Bipartite (DFS)
Link: https://www.geeksforgeeks.org/bipartite-graph/
Approach: Convert edge list to adjacency list. Use DFS to try coloring each node with 0/1 alternately.
If any neighbor has the same color, return false. Repeat for all disconnected components.
Time: O(V + E), Space: O(V)
Date: July 8, 2025
*/

class Solution {
  private:
    bool dfs(int start, int V, vector<int>& color, vector<int> adj[], int currColor) {
        color[start] = currColor;
        for (auto it : adj[start]) {
            if (color[it] == -1) {    
                if (!dfs(it, V, color, adj, !currColor)) return false;
            }
            else if (color[it] == color[start]) return false;
        }
        return true;
    }

  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> color(V, -1);

        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, V, color, adj, 0)) return false;
            }
        }
        return true;
    }
};
