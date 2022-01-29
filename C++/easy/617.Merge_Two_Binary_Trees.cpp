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
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1) return root2;
    if (!root2) return root1;
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
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
  TreeNode *node11 = new TreeNode(1);
  TreeNode *node12 = new TreeNode(3);
  TreeNode *node13 = new TreeNode(2);
  TreeNode *node14 = new TreeNode(5);
  node11->left = node12;
  node11->right = node13;
  node12->left = node14;
  node12->right = NULL;
  node13->left = NULL;
  node13->right = NULL;
  node14->left = NULL;
  node14->right = NULL;

  TreeNode *node21 = new TreeNode(2);
  TreeNode *node22 = new TreeNode(1);
  TreeNode *node23 = new TreeNode(3);
  TreeNode *node25 = new TreeNode(4);
  TreeNode *node27 = new TreeNode(7);

  node21->left = node22;
  node21->right = node23;
  node22->left = NULL;
  node22->right = node25;
  node23->left = NULL;
  node23->right = node27;
  node25->left = NULL;
  node25->right = NULL;
  node27->left = NULL;
  node27->right = NULL;

  Levelorder(node11);
  cout << endl;
  Levelorder(node21);

  return 0;
}