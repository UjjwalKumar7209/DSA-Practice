/*
Problem: Shortest Distance in Weighted Undirected Graph using Dijkstra  
Platform: Custom / GFG  
Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1  
Approach:
- Convert edge list into adjacency list with weight pairs.
- Use a min-heap (priority_queue with greater) to always expand the node with the smallest distance.
- For each node, relax its edges: if a shorter path is found to an adjacent node, update it and push to the queue.
- This ensures we always find the shortest path to all nodes from source.
Time: O(E × logV), where E = number of edges, V = number of vertices  
Space: O(V + E), for adjacency list and distance array  
Date: July 18, 2025
*/

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int, int>> adj[V];
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int dst = pq.top().first;
            pq.pop();
            for (auto& it: adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if (dst+edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dst + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
