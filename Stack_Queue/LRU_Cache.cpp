/*
Problem: LRU Cache (LeetCode #146)
Link: https://leetcode.com/problems/lru-cache/
Approach: Use a doubly linked list to keep track of usage order and a hashmap for O(1) access to nodes.
- `get` updates node position to most recently used.
- `put` inserts new or updates existing node and removes least recently used if capacity exceeded.
Time Complexity: O(1) for both get and put operations.
Space Complexity: O(capacity) for storing cache entries.
Date: June 11, 2025
*/


class Node {
  public:
  int key, value;
  Node* prev;
  Node* next;

  Node(int key_, int val_) {
      key = key_;
      value = val_;
      prev = nullptr;
      next = nullptr;
  }
};

class LRUCache {
private:
  void deleteNode(Node* node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
  }

  void insertAfterHead(Node* node) {
      Node* front = head->next;
      head->next = node;
      node->prev = head;
      node->next = front;
      front->prev = node;
  }
public:
  int capacity_;
  unordered_map<int, Node*> mpp;
  Node* head;
  Node* tail;

  LRUCache(int capacity) {
      capacity_ = capacity;
      head = new Node(-1, -1);
      tail = new Node(-1, -1);
      head->next = tail;
      tail->prev = head;
      mpp.clear();
  }
  
  int get(int key) {
      if (mpp.find(key) != mpp.end()) {
          deleteNode(mpp[key]);
          insertAfterHead(mpp[key]);
          return mpp[key]->value;
      }
      return -1;
  }
  
  void put(int key, int value) {
      if (mpp.find(key) != mpp.end()) {
          Node* temp = mpp[key];
          temp->value = value;
          deleteNode(temp);
          insertAfterHead(temp);
      }
      else {
          if (mpp.size() == capacity_) {
              Node* temp = tail->prev;
              mpp.erase(temp->key);
              deleteNode(temp);
              delete temp;
          }
          Node* newNode = new Node(key, value);
          mpp[key] = newNode;
          insertAfterHead(newNode);
      }
  }
};
