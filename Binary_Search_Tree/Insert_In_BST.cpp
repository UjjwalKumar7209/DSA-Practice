/*
Problem: Insert into a Binary Search Tree (LeetCode #701)
Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
Approach: Iteratively traverse the BST and insert the node at the correct position based on value.
Time: O(log₂n), Space: O(log₂n) for recursion or O(1) iterative
Date: June 25, 2025
*/

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    TreeNode* curr = root;
    while (true) {
        if (curr->val < val) {
            if (curr->right != NULL) {
                curr = curr->right;
            }
            else {
                curr->right = new TreeNode(val);
                break;
            }
        }
        else {
            if (curr->left != NULL) {
                curr = curr->left;
            }
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}
