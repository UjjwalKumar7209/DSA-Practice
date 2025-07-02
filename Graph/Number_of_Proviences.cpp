/*
Problem: Number of Provinces (Connected Components in Undirected Graph)
Link: https://leetcode.com/problems/number-of-provinces/
Approach: Convert adjacency matrix to list and use DFS to count connected components.
Time: O(N + V + 2E), Space: O(2N)
Where V = number of nodes, E = number of edges
Date: July 2, 2025
*/

class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it: adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        // Converting the matrix to list based
        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};
