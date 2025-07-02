/*
Problem: BFS Traversal of Graph
Link: https://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
Approach: Use a queue and visited array to traverse nodes level by level starting from node 0.
Time: O(V + E), Space: O(V)
Where V = number of vertices, E = number of edges
Date: July 2, 2025
*/

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for (auto it: adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};
