/*
Problem: Right View of Binary Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
Approach: Use level order traversal (BFS) and pick the last node of each level.
Time: O(2n), Space: O(n)
Date: June 19, 2025
*/

void getAnswer(TreeNode* root, int level, vector<int>& ans) {
    if (root == NULL) return;

    if (level == ans.size()) {
        ans.push_back(root->val);
    }

    getAnswer(root->right, level+1, ans);
    getAnswer(root->left, level+1, ans);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    getAnswer(root, 0, ans);
    return ans;
}
