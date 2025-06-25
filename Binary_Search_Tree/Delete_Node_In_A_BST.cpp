/*
Problem: Delete Node in a BST (LeetCode #450)
Link: https://leetcode.com/problems/delete-node-in-a-bst/
Approach: Search for the node, then handle three cases – no child, one child, or two children (replace with inorder successor).
Time: O(log₂n), Space: O(log₂n) for recursion, O(1) for iterative
Date: June 25, 2025
*/

class Solution {
private:
    TreeNode* getLeftRight(TreeNode* root) {
        while(root->right) {
            root = root->right;
        }
        return root;
    }

    TreeNode* helper(TreeNode* root) {
        if (!root->left) return root->right;
        else if(!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* leftChild = getLeftRight(root->left);
        leftChild->right = rightChild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (root->val == key) return helper(root);

        TreeNode* dummy = root;
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};
