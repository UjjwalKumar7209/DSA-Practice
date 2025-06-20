/*
Problem: Lowest Common Ancestor of a Binary Tree (LeetCode #236)
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Approach: Use post-order DFS to find the node where one key is in the left subtree and the other is in the right.
Time: O(2n), Space: O(h) where h is the height of the tree
Date: June 20, 2025
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (!left) {
        return right;
    }
    else if (!right) {
        return left;
    }
    else {
        return root;
    }
}
