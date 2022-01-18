#include <iostream>
#include <queue>
#include <vector>
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
  TreeNode *invertTree(TreeNode *root) {
    if (root == NULL) return NULL;
    TreeNode *left;
    TreeNode *right;
    left = invertTree(root->left);
    right = invertTree(root->right);
    root->left = right;
    root->right = left;

    return root;
  }
};
/*
class Solution {
  bool isMirror(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1 == NULL || t2 == NULL) return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) &&
           isMirror(t1->left, t2->right);
  }

 public:
  bool isSymmetric(TreeNode *root) {
      return isMirror(root, root);
    }
};
*/

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
  TreeNode *node1 = new TreeNode(4);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(7);
  TreeNode *node4 = new TreeNode(1);
  TreeNode *node5 = new TreeNode(3);
  TreeNode *node6 = new TreeNode(6);
  TreeNode *node7 = new TreeNode(9);
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

  Solution sol;
  TreeNode *output = sol.invertTree(node1);
  Levelorder(output);

  return 0;
}
