/*
Problem: Shortest Path in Directed Acyclic Graph (DAG)  
Platform: GFG  
Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1  
Approach:
- Create an adjacency list where each entry stores pairs {destination, weight}.
- Perform **Topological Sort** using DFS to get linear ordering of nodes.
- Initialize distance of source node (0) as 0 and rest as ∞ (INT_MAX).
- Traverse the topo order and relax edges for each node to update shortest distances.
- If a node's distance remains INT_MAX, mark it as -1 (unreachable).
Time: O(V + E), Space: O(V + E)  
Date: July 11, 2025
*/

// User function Template for C++
class Solution {
  private:
    void topoDFS(int node, vector<int>& vis, vector<pair<int, int>> adj[], stack<int>& st) {
        vis[node]  = 1;
        
        for (auto& it: adj[node]) {
            int v = it.first;
            if (!vis[v]) topoDFS(v, vis, adj, st);
        }
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        
        // Step-1  ------>  Do Topo Sort
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoDFS(i, vis, adj, st);
            }
        }
        
        // Step-2 -------> Relaxation of edges
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            
            for (auto& it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
