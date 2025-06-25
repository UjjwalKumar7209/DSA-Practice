/*
Problem: Ceil in a Binary Search Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
Approach: Traverse the BST and track the closest greater or equal value to the key.
Time: O(h), Space: O(1)
Date: June 25, 2025
*/

int findCeil(Node* root, int input) {
    int ceil = -1;
    while (root) {
        if (root->data == input) {
            ceil = root->data;
            return ceil;
        }
        else if (root->data > input) {
            ceil = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return ceil;
}
