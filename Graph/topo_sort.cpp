/*
Problem: Topological Sort (DFS)
Platform: GFG
Link: https://www.geeksforgeeks.org/problems/topological-sort/1
Approach: We perform DFS on each unvisited node. Once all its adjacent nodes are visited,
we push the current node into a stack. This ensures that a node appears after all its
dependencies. Finally, we pop elements from the stack to get the topological ordering.
Time: O(V + E), Space: O(V + E) for adj list and recursion stack
Date: July 10, 2025
*/

class Solution {
  private:
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (auto it: adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }

  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
