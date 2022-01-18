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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == NULL) return false;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL) {
      if (targetSum == 0)
        return true;
      else
        return false;
    }
    return hasPathSum(root->left, targetSum) ||
           hasPathSum(root->right, targetSum);
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
  TreeNode *node1 = new TreeNode(1);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(3);
  node1->left = node2;
  node1->right = node3;
  node2->left = NULL;
  node2->right = NULL;
  node3->left = NULL;
  node3->right = NULL;

  Solution sol;
  int target = 5;
  cout << (sol.hasPathSum(node1, target) ? "true" : "false") << endl;
  return 0;
}
