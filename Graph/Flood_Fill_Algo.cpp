/*
Problem: Flood Fill Algorithm (DFS-based)
Link: https://leetcode.com/problems/flood-fill/
Approach: Perform DFS from the source cell and recolor all connected cells with the same initial color.
Time: O(N × M), Space: O(N × M) for recursion and visited tracking
Where N = number of rows, M = number of columns
Date: July 5, 2025
*/

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int dr[], int dc[], int color, int iniColor) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == iniColor && ans[nRow][nCol] != color) {
                dfs(nRow, nCol, ans, image, dr, dc, color, iniColor);
            }
        }
    } 

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, dr, dc, color, iniColor);
        return ans;
    }
};
