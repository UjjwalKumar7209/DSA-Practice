/*
Problem: Detect Cycle in an Undirected Graph using DFS
Link: https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-dfs/
Approach: For each unvisited node, do DFS. If we visit a visited node that is not the parent, a cycle exists.
Time: O(V + 2E), Space: O(V)
Where V = number of vertices, E = number of edges
Date: July 7, 2025
*/

class Graph {
private:
    bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, node, vis, adj) == true) return true;
            }
            else if (it != parent) {
                return true;
            }
        }
        return false;
    }
public:
    bool detectCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj) == true) {
                    return true;
                }
            }
        }
        return false;
    }
};
