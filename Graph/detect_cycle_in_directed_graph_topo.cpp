/*
Problem: Detect Cycle in a Directed Graph (Using Kahn's Algorithm)
Platform: CodeStudio (or equivalent)
Link: https://www.codingninjas.com/studio/problems/detect-cycle-in-a-directed-graph_1062626
Approach:
- Build adjacency list from edge list.
- Compute indegree for each node.
- Apply Kahn’s Algorithm: Push all nodes with indegree 0 into a queue.
- For each node removed from the queue, reduce indegree of its neighbors.
- If a neighbor’s indegree becomes 0, push it into the queue.
- Count how many nodes were processed.
- If count != n, it means there's a cycle.
Time: O(N + E), Space: O(N + E)
Date: July 10, 2025
*/

#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<vector<int>> adj(n+1);
  for (auto edge: edges) {
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
  }

  vector<int> indegree(n+1, 0);
  for (int i = 1; i <= n; i++) {
    for (auto it: adj[i]) {
      indegree[it]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  int count = 0;
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    count++;
    for (auto it: adj[node]) {
      indegree[it]--;
      if (indegree[it] == 0) q.push(it);
    }
  }

  return (count != n);
}
