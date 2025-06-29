/*
Problem: Jump Game (Can you reach the last index?)
Link: https://leetcode.com/problems/jump-game/
Approach: Track the farthest reachable index while iterating through the array. If current position exceeds max reachable index, return false.
Time: O(n), Space: O(1)
Date: June 29, 2025
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) return false;
            maxIndex = max(maxIndex, nums[i] + i);
        }
        return true;
    }
};
