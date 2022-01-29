#include <iostream>
#include <queue>
#include <stack>
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
  void postorderTraversal(TreeNode *root, vector<int> &ans) {
    if (root == nullptr) return;
    postorderTraversal(root->left, ans);
    postorderTraversal(root->right, ans);
    ans.push_back(root->val);
  }

 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    postorderTraversal(root, ans);
    return ans;
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
  node1->left = NULL;
  node1->right = node2;
  node2->left = node3;
  node2->right = NULL;
  node3->left = NULL;
  node3->right = NULL;
  Solution sol;
  vector<int> output;
  output = sol.postorderTraversal(node1);
  for (int i = 0; i < output.size(); i++) {
    cout << output[i] << " ";
  }
  return 0;
}