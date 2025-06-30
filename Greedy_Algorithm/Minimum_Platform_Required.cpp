/*
Problem: Minimum Platforms Required for a Railway
Link: https://www.geeksforgeeks.org/minimum-number-of-platforms-required-for-a-railway/
Approach: Sort arrival and departure times separately. Use two pointers to simulate platform usage in real time.
Time: O(n log n), Space: O(1)
Date: June 30, 2025
*/

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxCnt = 0;
        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};
