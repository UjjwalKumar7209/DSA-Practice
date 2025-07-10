/*
Problem: Topological Sort (Kahn's Algorithm - BFS)
Platform: GFG
Link: https://www.geeksforgeeks.org/problems/topological-sort/1
Approach: 
- First, build the adjacency list from the edge list.
- Compute the indegree for each node.
- Push all nodes with 0 indegree into a queue.
- While the queue isn't empty, pop a node, add to topo sort, and decrease the indegree of its neighbors.
- If any neighbor's indegree becomes 0, push it into the queue.
Time: O(V + E), Space: O(N)
Date: July 10, 2025
*/

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>> adj(v);
    for (auto edge : edges) {
        int u = edge[0];
        int dest = edge[1];
        adj[u].push_back(dest);
    }

    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return topo;
}
