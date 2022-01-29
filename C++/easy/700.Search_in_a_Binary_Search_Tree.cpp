#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode *searchBST(TreeNode *root, int val) {
    TreeNode *temp;
    if (root) {
      if (root->val == val) return root;
      if (root->val < val) {
        return searchBST(root->right, val);
      } else {
        return searchBST(root->left, val);
      }
    }
    return root;
  }
};

void Preorder(TreeNode *current) {
  if (current) {
    cout << current->val << " ";
    Preorder(current->left);
    Preorder(current->right);
  }
}

void Inorder(TreeNode *current) {
  if (current) {
    Inorder(current->left);
    cout << current->val << " ";
    Inorder(current->right);
  }
}

void Postorder(TreeNode *current) {
  if (current) {
    Postorder(current->left);
    Postorder(current->right);
    cout << current->val << " ";
  }
}

void Levelorder(TreeNode *head) {
  queue<TreeNode *> q;
  q.push(head);
  while (!q.empty()) {
    TreeNode *current = q.front();
    q.pop();
    cout << current->val << " ";
    if (current->left != NULL) q.push(current->left);
    if (current->right != NULL) q.push(current->right);
  }
}

int main() {
  Solution sol;
  TreeNode *node1 = new TreeNode(4);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(7);
  TreeNode *node4 = new TreeNode(1);
  TreeNode *node5 = new TreeNode(3);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = NULL;
  node3->right = NULL;
  node4->left = NULL;
  node4->right = NULL;
  node5->left = NULL;
  node5->right = NULL;
  int val = 2;
  TreeNode *output = sol.searchBST(node1, val);
  Levelorder(output);
  return 0;
}