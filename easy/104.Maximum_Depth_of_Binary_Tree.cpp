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
  int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
      int level_length = q.size();
      vector<int> levels;
      for (int i = 0; i < level_length; ++i) {
        TreeNode *current = q.front();
        q.pop();
        levels.push_back(current->val);
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
      }
      level++;
    }
    return level;
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
  TreeNode *node1 = new TreeNode(3);
  TreeNode *node2 = new TreeNode(9);
  TreeNode *node3 = new TreeNode(20);
  TreeNode *node4 = new TreeNode(15);
  TreeNode *node5 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = NULL;
  node2->right = NULL;
  node3->left = node4;
  node3->right = node5;
  node4->left = NULL;
  node4->right = NULL;
  node5->left = NULL;
  node5->right = NULL;

  int output;
  Solution sol;
  output = sol.maxDepth(node1);
  cout << output << endl;

  return 0;
}
