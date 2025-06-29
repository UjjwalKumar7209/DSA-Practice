/*
Problem: Largest BST in Binary Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/largest-bst/1
Approach: Use postorder traversal to check for BST property at each node while tracking size, min, and max.
Time: O(n), Space: O(n) for recursion and o(1) without recursion stack
Date: June 28, 2025
*/

class NodeValue {
    public:
        int maxNode, minNode, maxSize;
        
        NodeValue(int maxNode, int minNode, int maxSize) {
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSize = maxSize;
        }
};

class Solution {
  private:
    NodeValue getLargestBstHelper(Node* root) {
        if (!root) return NodeValue(INT_MIN, INT_MAX, 0);
        auto left = getLargestBstHelper(root->left);
        auto right = getLargestBstHelper(root->right);
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(max(right.maxNode, root->data), min(left.minNode, root->data), left.maxSize+right.maxSize+1);
        }
        return NodeValue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
    }
  public:
    int largestBst(Node *root) {
        return getLargestBstHelper(root).maxSize;
    }
};
