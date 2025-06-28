/*
Problem: Recover Binary Search Tree (LeetCode #99)
Link: https://leetcode.com/problems/recover-binary-search-tree/
Approach: Use inorder traversal to detect two misplaced nodes and swap their values to restore BST property.
Time: O(n), Space: O(log₂n) for recursion or O(1) with Morris traversal
Date: June 25, 2025
*/

class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (root == NULL) return;
        inorder(root->left);
        if (prev && (root->val < prev->val)) {
            if (!first) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
