/*
Problem: Maximum Width of Binary Tree (LeetCode #662)
Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
Approach: Use level order traversal with indexing to calculate width between first and last node at each level.
Time: O(2n), Space: O(n)
Date: June 20, 2025
*/

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    int ans = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int minimum_index = q.front().second;
        int size = q.size();
        int left, right;
        for (int i = 0; i < size; i++) {
            int cur_index = q.front().second - minimum_index;
            TreeNode* node = q.front().first;
            q.pop();
            if (i == 0) left = cur_index;
            if (i == size - 1) right = cur_index;
            if (node->left) q.push({node->left, (long long)cur_index*2+1});
            if (node->right) q.push({node->right, (long long)cur_index*2+2});
        }
        ans = max(ans, right-left+1);
    }
    return ans;
}
