/*
Problem: Floor in a Binary Search Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/floor-in-bst/1
Approach: Traverse the BST and track the closest smaller or equal value to the key.
Time: O(h), Space: O(1)
Date: June 25, 2025
*/

int floor(Node* root, int x) {
    int floor = -1;
    while (root) {
        if (root->data == x) {
            floor = root->data;
            return floor;
        }
        else if (root->data < x) {
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    return floor;
}
