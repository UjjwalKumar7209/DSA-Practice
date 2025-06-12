/*
Problem: Sliding Window Maximum (LeetCode #239)
Link: https://leetcode.com/problems/sliding-window-maximum/
Approach: Use deque to store indices of useful elements for the current window in decreasing order.
Time: O(n), Space: O(k)
Date: June 12, 2025
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> list;
      deque<pair<int, int>> dq;
      for (int i = 0; i < nums.size(); i++) {
          if (!dq.empty() && dq.front().first == i-k) {
              dq.pop_front();
          }
          while (!dq.empty() && dq.back().second <= nums[i]) {
              dq.pop_back();
          }
          dq.push_back({i, nums[i]});
          if (i >= k-1) list.push_back(dq.front().second);
      }
      return list;
  }
