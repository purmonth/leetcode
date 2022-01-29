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
  void Inorder(TreeNode *current, vector<int> &output) {
    if (current) {
      Inorder(current->left, output);
      // cout << current->val << " ";
      output.push_back(current->val);
      Inorder(current->right, output);
    }
  }

 public:
  bool findTarget(TreeNode *root, int k) {
    vector<int> output;
    Inorder(root, output);
    int r = output.size() - 1;
    int l = 0;
    int sum = 0;
    while (l < r) {
      sum = output[l] + output[r];
      if (sum == k) return true;
      if (sum > k) {
        r--;
      } else {
        l++;
      }
    }
    return false;
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
  TreeNode *node2 = new TreeNode(3);
  TreeNode *node3 = new TreeNode(6);
  TreeNode *node4 = new TreeNode(2);
  TreeNode *node5 = new TreeNode(4);
  TreeNode *node7 = new TreeNode(7);
  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node2->right = node5;
  node3->left = NULL;
  node3->right = node7;
  node4->left = NULL;
  node4->right = NULL;
  node5->left = NULL;
  node5->right = NULL;
  node7->left = NULL;
  node7->right = NULL;
  Solution sol;
  cout << (sol.findTarget(node1, 1) ? "true" : "false");
  return 0;
}