/*
Problem: Non-overlapping Intervals (Minimum number to remove)
Link: https://leetcode.com/problems/non-overlapping-intervals/
Approach: Sort intervals by end time and greedily count the maximum number of non-overlapping intervals. Subtract from total to get removals.
Time: O(n + n log n), Space: O(1)
Date: June 30, 2025
*/

class Solution {
private:
    static bool comp(vector<int> val1, vector<int> val2) {
        return val1[1] < val2[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int lastEndTime = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= lastEndTime) {
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }
        return intervals.size() - cnt;
    }
};
