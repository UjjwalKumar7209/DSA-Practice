/*
Problem: DFS Traversal of Graph
Link: https://www.geeksforgeeks.org/depth-first-traversal-for-a-graph/
Approach: Use a recursive helper function to explore all unvisited neighbors starting from node 0.
Time: O(V + E), Space: O(V)
Where V = number of vertices, E = number of edges
Date: July 2, 2025
*/

class Solution {
  private:
    void dfsHelper(int node, vector<vector<int>> & adj, vector<int>& vis, vector<int>& ls) {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it: adj[node]) {
            if (!vis[it]) {
                dfsHelper(it, adj, vis, ls);
            }
        }
    }

  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        int start = 0;
        vector<int> ls;
        dfsHelper(start, adj, vis, ls);
        return ls;
    }
};
