/*
Problem: Online Stock Span (LeetCode #901)
Link: https://leetcode.com/problems/online-stock-span/
Approach: Use a monotonic stack to store prices and their spans; pop until current price is less.
Time: O(n), Space: O(n)
Date: June 11, 2025
*/

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind = -1;
    StockSpanner() {
        ind = -1;
        st = stack<pair<int, int>> ();
    }
    
    int next(int price) {
        ind += 1;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int ans = ind - (st.empty()? -1: st.top().second);
        st.push({price, ind});
        return ans;
    }
};
