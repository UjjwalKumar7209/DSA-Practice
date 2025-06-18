/*
Problem: Binary Tree Zigzag Level Order Traversal (LeetCode #103)
Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Approach: Use BFS with queue and reverse alternate levels using (size - i - 1) to get zigzag pattern.
Time: O(n), Space: O(n)
Date: June 18, 2025
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++) {
            TreeNode* temp = q.front();
            q.pop();
            int index = leftToRight? i: (size-i-1);
            level[index] = temp->val;
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        ans.push_back(level);
        leftToRight = !leftToRight;
    }
    return ans;
}
