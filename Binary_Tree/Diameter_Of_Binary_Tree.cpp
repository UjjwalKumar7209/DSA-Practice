/*
Problem: Diameter of Binary Tree (LeetCode #543)
Link: https://leetcode.com/problems/diameter-of-binary-tree/
Approach: Use post-order DFS to calculate the longest path through each node while computing height.
Time: O(n), Space: O(h) where h is the height of the tree
Date: June 17, 2025
*/

int height(TreeNode* node, int &diameter) {
    if (!node) return 0;
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, (lh+rh));
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
