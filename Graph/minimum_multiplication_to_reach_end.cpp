/*
GFG: https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
Date: July 27, 2025

Problem:
Minimum Multiplications to Reach End

Approach:
- Use BFS starting from `start` where each state is represented as {steps, node}.
- Multiply the current node with each element in `arr` and take modulo 100000 to stay in bounds.
- Maintain a `dist[]` array to store the minimum steps required to reach any number.
- If we reach `end`, return the number of steps taken.
- If BFS ends and `end` is unreachable, return -1.

Time Complexity: O(N * 10⁵) where N = size of arr (since max 100000 states, each explored once)  {Hypothetically it is possible but not really}
Space Complexity: O(10⁵)
*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        // {steps, node};
        queue<pair<int, int>> q;
        q.push({0, start});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;
        while (!q.empty()) {
            int node = q.front().second;
            int steps = q.front().first;
            q.pop();
            for (auto& it: arr) {
                int num = (it*node) % mod;
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;
                    if (num == end) return steps + 1;
                    q.push({steps+1, num});
                }
            }
        }
        return -1;
    }
};
