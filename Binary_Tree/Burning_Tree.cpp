/*
Problem: Burning Tree (GFG)
Link: https://www.geeksforgeeks.org/problems/burning-tree/1
Approach: Convert the tree to an undirected graph using a map to store parent references. Then perform BFS from the target node to simulate the burn level by level.
Time: O(2n + n·log n), Space: O(n)
Date: June 22, 2025
*/


/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    Node* getParent(Node*root, int target, unordered_map<Node*, Node*> &parent) {
        queue<Node*> q;
        q.push(root);
        Node* res;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) res = curr;
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return res;
    }
    
    int getTime(Node* root, Node* target, unordered_map<Node*, Node*> &parent) {
        queue<Node*> q;
        unordered_map<Node*, bool> visited;
        q.push(target);
        visited[target] = true;
        int time = 0;
        while (!q.empty()) {
            int flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    flag = 1;
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right && !visited[curr->right]) {
                    flag = 1;
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] && !visited[parent[curr]]) {
                    flag = 1;
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            if (flag) time++;
        }
        return time;
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = getParent(root, target, parent);
        int time = getTime(root, targetNode, parent);
        return time;
    }
};
