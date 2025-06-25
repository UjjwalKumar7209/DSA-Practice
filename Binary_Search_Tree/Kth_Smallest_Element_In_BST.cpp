/*
Problem: Kth Smallest Element in a BST (LeetCode #230)
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Approach: Do inorder traversal (iterative or recursive) to access elements in sorted order and return the kth one.
Time: O(log₂n + k), Space: O(log₂n) for recursion or iterative stack
Date: June 25, 2025
*/

class Solution {
private:
    int getNumber(TreeNode* root, int& cnt, int k) {
        if (!root) return -1;
        int left = getNumber(root->left, cnt, k);
        if (left != -1) return left;

        cnt++;
        if (cnt == k) return root->val;

        int right = getNumber(root->right, cnt, k);
        return right;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return getNumber(root, cnt, k);
    }
};
