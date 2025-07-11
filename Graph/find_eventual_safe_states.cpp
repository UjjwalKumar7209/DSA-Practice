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
//##############################################   U S I N G   DFS   ######################################################

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














/*
Problem: 802. Find Eventual Safe States  
Platform: LeetCode  
Link: https://leetcode.com/problems/find-eventual-safe-states/  
Approach:
- Reverse the graph: For each edge u → v, store v → u in the reversed graph.
- Maintain an indegree array for the reversed graph.
- Nodes with 0 indegree in the reversed graph are terminal nodes in the original graph.
- Use Kahn’s Algorithm: push all nodes with 0 indegree into a queue and perform BFS.
- Nodes that can be processed are safe (cannot reach any cycle).
- Sort and return all safe nodes.
Time: O(V + E), Space: O(V + E)  
Date: July 11, 2025
*/
// ############################################   USINGG   TOPO SORT   ####################################################

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indegree[V] = {0};
        
        for (int i = 0; i < V; i++) {
            for (auto it: adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();
            for (auto& it: adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
