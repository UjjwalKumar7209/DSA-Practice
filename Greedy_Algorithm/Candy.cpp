/*
Problem: Candy Distribution
Link: https://leetcode.com/problems/candy/
Approach: Traverse ratings to find increasing and decreasing sequences. Track peaks and adjust total candies to meet all constraints.
Time: O(n), Space: O(1)
Date: July 1, 2025
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 1;
        int sum = 1;
        int n = ratings.size();
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }
            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                down += 1;
                i++;
            }
            if (down > peak) {
                sum += (down - peak);
            }
        }
        return sum;
    }
};
