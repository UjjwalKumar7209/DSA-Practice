/*
Problem: Same Tree (LeetCode #100)
Link: https://leetcode.com/problems/same-tree/
Approach: Use recursion to compare the values and structure of both trees node by node.
Time: O(n), Space: O(h) where h is the height of the tree
Date: June 17, 2025
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p==NULL || q==NULL) {
        return p==q;
    }

    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
