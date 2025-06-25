/*
Problem: Validate Binary Search Tree (LeetCode #98)
Link: https://leetcode.com/problems/validate-binary-search-tree/
Approach: Use inorder traversal or recursion with min-max bounds to ensure BST properties are not violated.
Time: O(n), Space: O(log₂n) for recursion
Date: June 25, 2025
*/

class Solution {
private:
    bool isValid(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;
        if (root->val >= maxVal || root->val <= minVal) return false;

        return (isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
