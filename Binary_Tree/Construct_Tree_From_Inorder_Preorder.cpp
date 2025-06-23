/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal (LeetCode #105)
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Approach: Use recursion with a hash map to find root index in inorder traversal and construct left/right subtrees.
Time: O(n), Space: O(n)
Date: June 23, 2025
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorderIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int> &inorderIndex) {
        if (preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inorderRootIndex = inorderIndex[root->val];
        int numsLeft = inorderRootIndex - inStart;
        root->left = buildTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inorderRootIndex-1, inorderIndex);
        root->right = buildTree(preorder, preStart+numsLeft+1, preEnd, inorder, inorderRootIndex+1, inEnd, inorderIndex);
        return root;
    }
};
