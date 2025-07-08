/*
Problem: Is Graph Bipartite?
Link: https://leetcode.com/problems/is-graph-bipartite/
Approach: Use BFS to try coloring each connected component with two colors.
If any adjacent nodes have the same color, it's not bipartite.
Use a color array initialized to -1 to track unvisited nodes.
Time: O(V + E), Space: O(V)
Date: July 8, 2025
*/

class Solution {
private:
    bool check(int start, int V, vector<int>& color, vector<vector<int>>& graph) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (check(i, V, color, graph) == false)
                    return false;
            }
        }
        return true;
    }
};
