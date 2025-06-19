/*
Problem: Symmetric Tree (LeetCode #101)
Link: https://leetcode.com/problems/symmetric-tree/
Approach: Use recursion to check if left and right subtrees are mirror images of each other.
Time: O(n), Space: O(n) where h is the height of the tree
Date: June 19, 2025
*/

bool isSymmetricCheck(TreeNode* left, TreeNode* right) {
    if (!left || !right) return left==right;

    if (left->val != right->val) return false;

    return isSymmetricCheck(left->left, right->right) && isSymmetricCheck(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return (root == NULL || isSymmetricCheck(root->left, root->right));
}
