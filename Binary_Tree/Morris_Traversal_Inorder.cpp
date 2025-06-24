/*
Problem: Flatten Binary Tree to Linked List (LeetCode #114)
Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Approach: Use reverse postorder (right -> left -> root) with a pointer to build the list in-place using recursion or Morris traversal.
Time: O(n), Space: O(h) for recursion stack or O(1) with Morris
Date: June 24, 2025
*/


void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            TreeNode* prev = curr->left;
            while (prev->right) {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
