/****************************************************************

💻 DSA Problem: Dijkstra’s Algorithm – Shortest Path from Node 1 to Node N  
📅 Date: July 22, 2025  
🌐 Platform: Custom

👨‍🏫 Approach:
• Build an adjacency list from the edge list.
• Use a min-priority queue (min-heap) to implement Dijkstra's algorithm.
• Track the shortest distance from node 1 to all other nodes using a `dist` array.
• Maintain a `parent` array to reconstruct the path from node 1 to node N.
• If node N is unreachable, return {-1}.
• Otherwise, backtrack using `parent` to build the path and return it with the total weight.

⏱️ Time Complexity: O(E · log₂V)  
🧠 Space Complexity: O(V + E)

****************************************************************/


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        dist[1] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            for (auto& it: adj[node]) {
                int adjNode = it.first;
                int edgeW = it.second;
                if (currDist + edgeW < dist[adjNode]) {
                    dist[adjNode] = currDist + edgeW;
                    pq.push({currDist + edgeW, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if (dist[n] == 1e9) return {-1};
        vector<int> path;
        int curr = n;
        while (curr != parent[curr]) {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        vector<int> ans;
        ans.push_back(dist[n]);
        for (int node : path) ans.push_back(node);
        return ans;
    }
};
