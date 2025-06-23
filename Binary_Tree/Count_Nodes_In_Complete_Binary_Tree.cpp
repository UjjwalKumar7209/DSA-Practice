/*
Problem: Count Complete Tree Nodes (LeetCode #222)
Link: https://leetcode.com/problems/count-complete-tree-nodes/
Approach: Use DFS and compare left and right subtree heights to determine if it's a perfect subtree and count efficiently.
Time: O(log² n), Space: O(log n)
Date: June 23, 2025
*/

class Solution {
private:
    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left; 
        }
        return height;
    }
    int getRightHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if (lh == rh) return (1<<lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
