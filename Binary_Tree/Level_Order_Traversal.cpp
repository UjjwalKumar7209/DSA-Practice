/*
Problem: Binary Tree Level Order Traversal (LeetCode #102)
Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Approach: Use a queue to traverse each level of the tree iteratively.
Time: O(n), Space: O(n)
Date: June 15, 2025
*/

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
