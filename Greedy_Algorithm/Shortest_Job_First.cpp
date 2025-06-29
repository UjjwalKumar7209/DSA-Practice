/*
Problem: Shortest Job First (SJF) – Simplified (All Arrival Times = 0)
Link: https://www.geeksforgeeks.org/program-for-shortest-job-first-sjf-scheduling-set-1-non-preemptive/
Approach: Sort burst times and compute cumulative waiting time to minimize average wait.
Time: O(n log n), Space: O(1)
Date: June 29, 2025
*/

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        int t = 0;
        int wt = 0;
        for (int i = 0; i < bt.size(); i++) {
            wt += t;
            t += bt[i];
        }
        return (wt/bt.size());
    }
};
