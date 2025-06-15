/*
Problem: Binary Tree Preorder Traversal (LeetCode #144)
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
Approach: Root → Left → Right; implemented using recursion or iterative stack.
Time: O(n), Space: O(n)
Date: June 15, 2025
*/


class PreOrder {
private:
    void preorderTraversalCode(vector<int> &ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        ans.push_back(root->val);
        preorderTraversalCode(ans, root->left);
        preorderTraversalCode(ans, root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraversalCode(ans, root);
        return ans;
    }
};
