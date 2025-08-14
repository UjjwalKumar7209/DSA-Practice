/*
-------------------------------------
🗓️ Date: 14th August  
📘 Topic: Graphs - Minimum Spanning Tree (MST)  
🔢 Problem: Minimum Spanning Tree  
🌐 Platform: GeeksforGeeks  
🔗 Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

🧠 Approach (Kruskal's Algorithm + Disjoint Set Union):
- We are given a connected, undirected, weighted graph.
- Goal: Find the sum of weights of edges included in the MST.
- **Disjoint Set (Union-Find)** is used to detect cycles efficiently:
    - `findUParent(node)` → Finds ultimate parent with path compression.
    - `unionBySize(u, v)` → Merges smaller set into larger set to keep tree shallow.
- Steps:
    1. Convert edge list into `{weight, u, v}` format.
    2. Sort edges by weight in ascending order.
    3. Iterate over edges:
        - If `u` and `v` belong to different components, include edge in MST and union them.
    4. Sum of included edges' weights = MST weight.

🕰️ Time Complexity: O(E log E) → Sorting dominates, where E = number of edges.  
🛢️ Space Complexity: O(V) → DSU parent and size arrays.  
-------------------------------------
*/

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> edge1;
        for (auto& edge: edges) {
            int wt = edge[2];
            int u = edge[0];
            int v = edge[1];
            edge1.push_back({wt, u, v});
        }
        
        DisjointSet ds(V);
        
        sort(edge1.begin(), edge1.end());
        int mstWeight = 0;
        for (auto& it: edge1) {
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            if (ds.findUParent(u) != ds.findUParent(v)) {
                mstWeight += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWeight;
    }
};
