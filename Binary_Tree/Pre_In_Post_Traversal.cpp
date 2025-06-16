/*
Problem: Preorder, Inorder, and Postorder Traversal in One Traversal
Link: https://www.geeksforgeeks.org/print-preorder-inorder-and-postorder-traversals-from-given-postorder-traversal/
Approach: Use a single stack with state-tracking for each node to simulate all three traversals.
Time: O(n), Space: O(n)
Date: June 12, 2025
*/


void preInPostTraversal(TreeNode* root) {
  if (root == NULL) return;
  stack<TreeNode*, int> st;
  vector<int> pre, in, post;
  st.push({root, 1});
  while (!st.empty()) {
    auto it = st.top();
    st.pop();
    if (it.second == 1) {
      pre.push_back(it.first->val);
      it.second++;
      if (it.first->left != NULL) {
        st.push({it.first->left, 1});
      }
    }
    else if (it.second == 2) {
      in.push_back(it.first->val);
      it.second++;
      if (st.first->right != NULL) {
        st.push({it.first->right, 1});
      }
    }
    else {
      in.push_back(it.first->va);
      it.second++;
    }
  }
}
