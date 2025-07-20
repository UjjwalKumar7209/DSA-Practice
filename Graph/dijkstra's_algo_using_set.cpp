/****************************************************************

💻 DSA Problem: Dijkstra’s Algorithm – Shortest Distance in an Undirected Weighted Graph  
📅 Date: July 20, 2025  
🌐 Platform: Custom (User Function Template)

👨‍🏫 Approach:
• Create an adjacency list from the given edge list.
• Use a set of pairs {distance, node} to always get the node with the smallest distance.
• Initialize all distances as infinity, except for the source node.
• For each node popped from the set, update distances of adjacent nodes if a shorter path is found.
• If a better distance is found and the node already exists in the set, erase the older pair and insert the updated one.
• Finally, return the distance array.

⏱️ Time Complexity: O(E · log₂V)  
🧠 Space Complexity: O(V + E)

****************************************************************/

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
        set<pair<int, int>> st;
        st.insert({0, src});
        dist[src] = 0;
        
        while (!st.empty()) {
            auto ite = *(st.begin());
            int node = ite.second;
            int dst = ite.first;
            st.erase(ite);
            
            for (auto it: adj[node]) {
                int adjNode = it.first;
                int edgeW = it.second;
                if (dst + edgeW < dist[adjNode]) {
                    // if already existed
                    if (dist[adjNode] != 1e9) {  // yeh isseliye kr rhe hai kuyoki humme agr
                    // koi chota distance wala mil gya hai toh there is no point of storing 
                    // the more distance one in the set...
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dst + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
