/*
Problem: Maximum Depth of Binary Tree (LeetCode #104)
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Approach: Use DFS recursion to find the max depth from root to leaf.
Time: O(n), Space: O(h) where h is the height of the tree
Date: June 17, 2025
*/

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return (1 + max(left, right));
}
