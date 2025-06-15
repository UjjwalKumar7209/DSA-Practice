/*
Problem: Binary Tree Inorder Traversal (LeetCode #94)
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
Approach: Left → Root → Right; implemented using recursion or iterative stack.
Time: O(n), Space: O(n)
Date: June 15, 2025
*/


class Inorder {
private:
    void inorderTraversalCode(vector<int> &ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversalCode(ans, root->left);
        ans.push_back(root->val);
        inorderTraversalCode(ans, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversalCode(ans, root);
        return ans;
    }
};
