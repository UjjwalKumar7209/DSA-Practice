/*
Problem: N Meetings in One Room
Link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
Approach: Sort meetings by their finishing times and greedily select meetings that start after the last selected meeting ends.
Time: O(n log n) due to sorting
Space: O(n) for storing meeting data
Date: June 29, 2025
*/

class Data {
public:
    int start;
    int end;
};

class Solution {
private:
    static bool comp(Data& a, Data& b) {
        return a.end < b.end;
    }
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Data> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
        }
        sort(arr.begin(), arr.end(), comp);
        int cnt = 1;
        int freeTime = arr[0].end;
        for (int i = 1; i < n; i++) {
            if (arr[i].start > freeTime) {
                cnt++;
                freeTime = arr[i].end;jm,.
            }
        }
        return cnt;
    }
};
