/*
Problem: Lowest Common Ancestor of a Binary Search Tree (LeetCode #235)
Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Approach: Use BST properties to traverse from root and find the split point between the two nodes.
Time: O(log₂n), Space: O(log₂n) for recursion, O(1) for iterative
Date: June 25, 2025
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
