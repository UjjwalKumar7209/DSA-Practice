/*
Problem: All Nodes Distance K in Binary Tree (LeetCode #863)
Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
Approach: Convert the binary tree into an undirected graph using a map to store parent references. Then perform BFS from the target node to find all nodes at distance K.
Time: O(2n + n·log n), Space: O(n)
Date: June 20, 2025
*/

void getParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    getParent(root, parent);
    int dist = 0;
    queue<TreeNode*> q;
    q.push(target);
    unordered_map<TreeNode*, bool> visited;
    visited[target] = true;
    while (!q.empty()) {
        int size = q.size();
        if (dist++ == k) break;
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (parent[curr] && !visited[parent[curr]]) {
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
    }
    vector<int> result;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }
    return result;
}
