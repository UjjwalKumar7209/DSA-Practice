/*
Problem: Serialize and Deserialize Binary Tree (LeetCode #297)
Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
Approach: Use level order (BFS) or preorder (DFS) to convert tree to string and back, handling nulls appropriately.
Time: O(n), Space: O(n)
Date: June 24, 2025
*/

string serialize(TreeNode* root) {
    if (root == NULL) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr == NULL) {
            s+="#,";
        }
        else {
            s += to_string(curr->val) + ",";
        }
        if (curr) {
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode* deserialize(string data) {
    if (data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        getline(s, str, ',');
        if (str == "#") {
            curr->left = NULL;
        }
        else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }
        getline(s, str, ',');
        if (str == "#") {
            curr->right = NULL;
        }
        else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
