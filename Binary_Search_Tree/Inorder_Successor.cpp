/*
Problem: Inorder Successor in BST (GFG)
Link: https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
Approach: Traverse the tree maintaining potential successor. Move left if current > target, else move right.
Time: O(h), Space: O(1)
Date: June 26, 2025
*/

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        Node* successor = NULL;
        while (root) {
            if (x->data >= root->data) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        return !successor? -1: successor->data;
    }
};
