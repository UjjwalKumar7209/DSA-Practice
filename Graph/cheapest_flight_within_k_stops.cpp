/*
LeetCode: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Date: July 27, 2025

Problem:
Cheapest Flights Within K Stops

Approach:
- We use a modified BFS (like Dijkstra) that keeps track of the number of stops taken so far.
- Each state in the queue is {stops, {node, totalCost}}.
- We build an adjacency list from the flight data.
- We only continue processing a path if the number of stops is within k.
- A `dist[]` array keeps the minimum cost to reach each node.
- If a shorter path with fewer or equal stops is found, we update and push it into the queue.

Time Complexity: O(k * E) — in the worst case, we may process each edge up to k times.
Space Complexity: O(N + E)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        // {stop, {node, dist}};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int dis = it.second.second;
            if (stop > k) continue;
            for (auto iter: adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;
                if (dis + edW < dist[adjNode] && stop <= k) {
                    dist[adjNode] = dis + edW;
                    q.push({stop+1, {adjNode, dis + edW}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
}; 
