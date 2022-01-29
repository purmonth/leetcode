#include <iostream>
#include <queue>
using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == NULL) return root;
    queue<Node*> q;
    q.push(root);
    int size = 0;
    while (!q.empty()) {
      size = q.size();
      for (int i = 0; i < size; i++) {
        Node* current = q.front();
        q.pop();
        cout << current->val << " ";
        if (i < size - 1) {
          current->next = q.front();
        }
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
      }
    }
    return root;
  }
};

void Levelorder(Node* head) {
  queue<Node*> q;
  q.push(head);
  while (!q.empty()) {
    Node* current = q.front();
    q.pop();
    cout << current->val << " ";
    if (current->left != NULL) q.push(current->left);
    if (current->right != NULL) q.push(current->right);
  }
}
int main() {
  Solution sol;
  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);
  Node* node4 = new Node(4);
  Node* node5 = new Node(5);
  Node* node6 = new Node(6);
  Node* node7 = new Node(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = node6;
  node3->right = node7;
  node4->left = NULL;
  node4->right = NULL;
  node5->left = NULL;
  node5->right = NULL;
  node6->left = NULL;
  node6->right = NULL;
  node7->left = NULL;
  node7->right = NULL;

  node1 = sol.connect(node1);

  return 0;
}