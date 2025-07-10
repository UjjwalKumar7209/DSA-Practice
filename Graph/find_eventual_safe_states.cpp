/*
Problem: 802. Find Eventual Safe States (DFS)
Link: https://leetcode.com/problems/find-eventual-safe-states/
Approach: Use DFS to detect cycles in the directed graph. Maintain three arrays:
`vis` to mark visited nodes, `pathVis` to track the current DFS path (for cycle detection),
and `check` to record safe nodes. Nodes involved in cycles are marked unsafe (check = 0).
After DFS, collect all nodes marked safe (check = 1) into the result.
Time: O(V + E), Space: O(3V)
Date: July 10, 2025
*/

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it: graph[node]) {
            if (!vis[it]) {
                if (dfs(it, graph, vis, pathVis, check)) {
                    check[it] = 0;
                    return true;
                }
            }
            else if (pathVis[it] == 1) {
                check[it] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0), pathVis(V, 0), check(V, 0), safeNodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
