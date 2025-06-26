/*
Problem: Two Sum in BST (LeetCode #653)
Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
Approach: Use two BSTIterator classes for inorder and reverse inorder traversal (two-pointer style). Maintains O(h) space with controlled stack usage.
Time: O(n), Space: O(h)
Date: June 26, 2025
*/

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while (i<j) {
            if (i+j == k) return true;
            else if(i+j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
