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
  bool isValidBST(TreeNode *root, TreeNode *min = NULL, TreeNode *max = NULL) {
    if (!root) return true;
    if (min != NULL && root->val <= min->val) return false;
    if (max != NULL && root->val >= max->val) return false;
    return isValidBST(root->left, min, root) &&
           isValidBST(root->right, root, max);
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
  TreeNode *node1 = new TreeNode(5);
  TreeNode *node2 = new TreeNode(4);
  TreeNode *node3 = new TreeNode(6);
  TreeNode *node6 = new TreeNode(3);
  TreeNode *node7 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = NULL;
  node2->right = NULL;
  node3->left = node6;
  node3->right = node7;
  node6->left = NULL;
  node6->right = NULL;
  node7->left = NULL;
  node7->right = NULL;
  Solution sol;
  cout << (sol.isValidBST(node1) ? "true" : "false") << endl;

  return 0;
}