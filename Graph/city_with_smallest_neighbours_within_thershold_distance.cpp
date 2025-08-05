/*
-------------------------------------
🗓️ Date: 5th August  
📘 Topic: Graphs  
🔢 Problem: Find the City With the Smallest Number of Neighbors at a Threshold Distance  
🌐 Platform: Leetcode  
🔗 Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

🧠 Approach (Floyd-Warshall Algorithm):
- We are given an undirected weighted graph.
- We first initialize a 2D matrix `dist` where `dist[i][j]` keeps the shortest distance from city `i` to city `j`.
- Initially, set all distances to a large number (`1e9`) and `dist[i][i] = 0`.
- Then, for every edge, initialize the distance directly between the connected nodes.
- Use Floyd-Warshall algorithm:
    - For every node `via`, try updating all `dist[i][j]` using the path through `via`.
- After all-pairs shortest paths are calculated, count how many cities are reachable from each city within the given threshold.
- Track the city with the minimum number of such reachable cities.
- If multiple cities tie, return the one with the **greatest number** (as per problem requirement).

🕰️ Time Complexity: O(N^3)  
🛢️ Space Complexity: O(N^2)  
-------------------------------------
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto& edge: edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != 1e9 && dist[via][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dist[city][adjCity] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};
