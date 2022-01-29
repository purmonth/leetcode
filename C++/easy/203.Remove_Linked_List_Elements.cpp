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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* temp;
    ListNode* prehead = new ListNode(0);
    ListNode* prev;
    prehead->next = head;
    prev = prehead;
    temp = head;
    while (temp != NULL) {
      if (temp->val == val) {
        prev->next = temp->next;
      } else {
        prev = temp;
      }
      temp = temp->next;
    }
    return prehead->next;
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
  ListNode* node2 = new ListNode(6);
  ListNode* node3 = new ListNode(6);
  ListNode* node4 = new ListNode(6);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(6);
  ListNode* node7 = new ListNode(6);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  node5->next = node7;
  node7->next = NULL;
  traverseNode(node1);
  int value = 6;
  Solution sol;
  ListNode* output;
  output = sol.removeElements(node1, value);
  traverseNode(output);

  return 0;
}