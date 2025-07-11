/*
Problem: 210. Course Schedule II  
Platform: LeetCode  
Link: https://leetcode.com/problems/course-schedule-ii/  
Approach:
- Create an adjacency list to represent the graph.
- For every prerequisite pair [a, b], add an edge from b → a (b must be done before a).
- Compute indegree of each course.
- Push all nodes with indegree 0 into a queue.
- Perform Kahn’s Algorithm (BFS) to find a valid topological ordering.
- If the result contains all courses, return it.
- Else, a cycle exists → return an empty array.
Time: O(V + E), Space: O(V + E)  
Date: July 10, 2025
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
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

        return (topo.size() == numCourses) ? topo : vector<int>{};
    }
};
