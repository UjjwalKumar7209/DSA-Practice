/*
Problem: The Celebrity Problem (GFG)
Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
Approach: Use stack to eliminate non-celebrities and verify the candidate in O(n) time.
Time: O(n), Space: O(1)
Date: June 12, 2025
*/

int celebrity(vector<vector<int> >& mat) {
    int top = 0;
    int down = mat.size()-1;
    while (top < down) {
        if (mat[top][down] == 1) {
            top++;
        }
        else if (mat[down][top] == 1) {
            down--;
        }
        else {
            top++;
            down--;
        }
    }
    if (top > down) return -1;
    for (int i = 0; i < mat.size(); i++) {
        if (i != top && (mat[top][i] == 1 || mat[i][top] == 0)) {
            return -1;
        }
    }
    return top;
}
