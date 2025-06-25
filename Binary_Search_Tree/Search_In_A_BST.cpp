/*
Problem: Search in a Binary Search Tree (LeetCode #700)
Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
Approach: Use recursion or iterative traversal by comparing target value with current node to follow BST property.
Time: O(h), Space: O(h) for recursion or O(1) iterative
Date: June 25, 2025
*/

TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL && root->val != val) {
        root = root->val > val? root = root->left: root = root->right;
    }
    return root;
}
