/*
Problem: Boundary Traversal of Binary Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
Approach: Traverse in 3 parts — left boundary (excluding leaves), leaf nodes, right boundary (excluding leaves in reverse).
Time: O(n), Space: O(h) where h is the height of the tree
Date: June 18, 2025
*/

class Solution {
  private:
    bool isLeaf(Node *root) {
        if (!root->left && !root->right) return true;
        return false;
    }
    
    void addLeftBoundary(Node *root, vector<int>& ans) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) {
                ans.push_back(cur->data);
            }
            if (cur->left) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
    }
    
    void addLeaf(Node* root, vector<int>& ans) {
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        
        if (root->left) addLeaf(root->left, ans);
        if (root->right) addLeaf(root->right, ans);
    }
    
    void addRightBoundary(Node* root, vector<int>& ans) {
        Node* cur = root->right;
        vector<int> temp;
        while (cur) {
            if (!isLeaf(cur)) temp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = temp.size()-1; i >=0; i--) {
            ans.push_back(temp[i]);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaf(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};
