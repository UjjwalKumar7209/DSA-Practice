/*
Problem: Largest Rectangle in Histogram (LeetCode #84)
Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
Approach: Go to every element and store in stack and whenever you found a smaller element go back and while going back
stack.top() will be your previous smaller element and the current smaller element will be your next smaller element. And then
do simple calculation (nextSmallerElementIndex - previousSmallerElementIndes - 1) will give you the width of the rectangle
and then multiply it with arr[i] then you will get the are. Store that area in the max variable and compare in every
iteration and so on.
Time: O(2n), Space: O(n)
Date: June 11, 2025
*/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1: st.top();
                maxi = max(maxi, heights[element]*(nse-pse-1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top();
            st.pop();
            int nse = heights.size();
            int pse = st.empty()? -1: st.top();
            maxi = max(maxi, heights[element]*(nse-pse-1));
        }
        return maxi;
    }
};
