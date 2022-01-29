#include <iostream>

using namespace std;

/**
 * definition for singly-linked list.
 *
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current;
    current = head;
    while (head != NULL && current->next != NULL) {
      if (current->val == current->next->val) {
        current->next = current->next->next;
      } else {
        current = current->next;
      }
    }
    return head;
  }
};

void traverseNode(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(1);
  ListNode* node3 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;
  traverseNode(node1);

  Solution sol;
  ListNode* output;
  output = sol.deleteDuplicates(node1);
  traverseNode(output);

  return 0;
}