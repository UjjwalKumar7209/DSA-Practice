/*
Problem: Construct Binary Search Tree from Preorder Traversal (LeetCode #1008)
Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
Approach: Use recursion with upper bounds to place nodes correctly based on BST properties while traversing preorder.
Time: O(3n), Space: O(1)
Date: June 26, 2025
*/

class Solution {
private:
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
