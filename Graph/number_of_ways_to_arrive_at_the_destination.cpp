/*
🗓️ Date: 27 July 2025
🔗 Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

🧠 Approach:
- Dijkstra's algorithm is used to find the shortest path from node 0 to node n-1.
- Maintain a `dist` array to store shortest distances and a `ways` array to store number of ways to reach each node with shortest path.
- For each node, if we find a shorter path, we update both distance and ways.
- If we find another path with same minimum distance, we add to the number of ways using modulo.

⏱️ Time Complexity: O(E * log₂V), where E = number of edges, V = number of vertices
📦 Space Complexity: O(V + E)
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        // {dist, node};
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        long long mod = (long long) 1e9 + 7;
        while (!pq.empty()) {
            int node = pq.top().second;
            long long dst = pq.top().first;
            pq.pop();
            for (auto& adjNode: adj[node]) {
                int adjN = adjNode.first;
                int edW = adjNode.second;
                // This is the first time that we are reaching the smaller distance;
                if (dst + edW < dist[adjN]) {
                    dist[adjN] = dst + edW;
                    pq.push({dst + edW, adjN});
                    ways[adjN] = ways[node];
                }
                // This is the another time when we are reaching at that distance at the same value;
                else if (dst + edW == dist[adjN]) {
                    ways[adjN] = (ways[adjN] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
