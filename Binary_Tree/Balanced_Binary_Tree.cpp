/*
Problem: Balanced Binary Tree (LeetCode #110)
Link: https://leetcode.com/problems/balanced-binary-tree/
Approach: Use post-order DFS to check balance of subtrees while calculating height.
Time: O(n), Space: O(h) where h is the height of the tree
Date: June 17, 2025
*/

int dfsHeight(TreeNode* root) {
    if (root == NULL) return 0;

    int lh = dfsHeight(root->left);
    if(lh == -1) return -1;
    int rh = dfsHeight(root->right);
    if (rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return max(lh, rh) + 1;
}

bool isBalanced(TreeNode* root) {
    return dfsHeight(root) != -1;
}
