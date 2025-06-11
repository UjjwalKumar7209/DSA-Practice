/*
Problem: Maximal Rectangles (Leetcode #85)
Link: https://leetcode.com/problems/maximal-rectangle/description/
Approach: Make another 2-D array for prefix sum and then for every row use the conecept of largest rectangle in histogram
question
and store it in a maximum variable and so on.
Time Complexit: o(n x m) + o(n x 2m)
Date: June 11, 2025
*/

class Solution {
private:
    int getLargeHisto(vector<int> arr) {
        stack<int> st;
        int maxVal = 0;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                int elem = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()? -1: st.top();
                maxVal = max(maxVal, (arr[elem]*(nse-pse-1)));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int elem = st.top();
            st.pop();
            int nse = arr.size();
            int pse = st.empty()? -1: st.top();
            maxVal = max(maxVal, arr[elem]*(nse-pse-1));
        }
        return maxVal;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pSum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum++;
                if (matrix[i][j] == '0') sum = 0;
                pSum[i][j] = sum;
            }
        }
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, getLargeHisto(pSum[i]));
        }
        return maxVal;
    }
};
