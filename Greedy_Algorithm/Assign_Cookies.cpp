/*
Problem: Assign Cookies (LeetCode #455)
Link: https://leetcode.com/problems/assign-cookies/
Approach: Sort both arrays; for each child, give the smallest possible cookie that satisfies their greed.
Time: O(n log n + m log m + m), Space: O(1)
Date: June 29, 2025
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int l = 0;
        int r = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while (l < n && r < m) {
            if (g[l]<=s[r]) {
                l++;
            }
            r++;
        }
        return l;
    }
};
