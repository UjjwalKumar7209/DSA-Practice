/*
Problem: Remove K Digits (LeetCode #402)
Link: https://leetcode.com/problems/remove-k-digits/
Approach: Use a monotonic stack to keep the smallest digits and remove peaks.
Time: O(n), Space: O(n)
Date: June 11, 2025
*/

string removeKdigits(string num, int k) {
    stack<char> st;
    for (int i = 0; i < num.size(); i++) {
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k > 0) {
        st.pop();
        k--;
    }
    if (st.empty()) return "0";
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    while (res.size() != 0 && res.back() == '0') {
        res.pop_back();
    }
    if (res.empty()) return "0";
    reverse(res.begin(), res.end());
    return res;
}
