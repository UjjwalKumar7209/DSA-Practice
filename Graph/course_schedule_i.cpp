/*
Problem: 207. Course Schedule
Platform: LeetCode
Link: https://leetcode.com/problems/course-schedule/
Approach:
- Construct the directed graph from prerequisites.
- Calculate the indegree of each node (course).
- Push all courses with indegree 0 into a queue.
- Use Kahn’s algorithm (BFS) to process nodes.
- For every node processed, reduce indegree of its neighbors.
- If all nodes are processed (cnt == numCourses), return true (possible to finish all courses).
- Otherwise, a cycle exists, return false.
Time: O(V + E), Space: O(V + E)
Date: July 10, 2025
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it: adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        return cnt == numCourses;
    }
};
