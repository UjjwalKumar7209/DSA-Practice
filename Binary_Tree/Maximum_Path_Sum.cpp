/*
Problem: Binary Tree Maximum Path Sum (LeetCode #124)
Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
Approach: Use post-order DFS to calculate max gain from each node and update global max path sum.
Time: O(n), Space: O(h) where h is the height of the tree
Date: June 17, 2025
*/

int getMax(TreeNode* root, int &maxi) {
    if (!root) return 0;
    
    int lh = max(0, getMax(root->left, maxi));
    int rh = max(0, getMax(root->right, maxi));

    maxi = max(maxi, lh+rh+root->val);
    
    return (root->val + max(lh, rh));
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    getMax(root, maxi);
    return maxi;
}
