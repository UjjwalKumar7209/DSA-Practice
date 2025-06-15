/*
Problem: Binary Tree Postorder Traversal (LeetCode #145)
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
Approach: Left → Right → Root; implemented using recursion or two-stack iteration.
Time: O(n), Space: O(n)
Date: June 15, 2025
*/


class Postorder {
private:
    void postorderTraversalCode(vector<int> &ans, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        postorderTraversalCode(ans, root->left);
        postorderTraversalCode(ans, root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversalCode(ans, root);
        return ans;
    }
};
