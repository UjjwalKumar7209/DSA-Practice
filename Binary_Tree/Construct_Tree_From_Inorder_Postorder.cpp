/*
Problem: Construct Binary Tree from Inorder and Postorder Traversal (LeetCode #106)
Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Approach: Use a hashmap to store inorder indices and recursively build the tree from postorder (right to left).
Time: O(n), Space: O(n)
Date: June 24, 2025
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        unordered_map<int, int> hm;
        for (int i = 0; i < inorder.size(); i++) {
            hm[inorder[i]] = i;
        }
        TreeNode* root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, hm);
        return root;
    }
    TreeNode* buildTree(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, unordered_map<int, int> &hm) {
        if (ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = hm[root->val];
        int numsLeft = inRoot - is;
        root->left = buildTree(inorder, is, inRoot-1, postorder, ps, ps+numsLeft-1, hm);
        root->right = buildTree(inorder, inRoot+1, ie, postorder, ps+numsLeft, pe-1, hm);
        return root;
    }
};
