/*
Problem: Bottom View of Binary Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
Approach: Use BFS with a queue and a map to overwrite the node at each horizontal distance.
Time: O(n + n·log n) ≈ O(n·log n), Space: O(n)
Date: June 19, 2025
*/

vector<int> bottomView(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;
    map<int, int> mpp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        int line = it.second;
        Node* node = it.first;
        mpp[line] = node->data;
        if (node->left) {
            q.push({node->left, line-1});
        }
        if (node->right) {
            q.push({node->right, line+1});
        }
    }
    for (auto it: mpp) {
        ans.push_back(it.second);
    }
    return ans;
}
