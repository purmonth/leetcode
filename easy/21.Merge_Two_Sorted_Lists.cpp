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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* prehead = new ListNode(-1);
    ListNode* prev = prehead;
    while (list1 != NULL && list2 != NULL) {
      if (list1->val <= list2->val) {
        prev->next = list1;
        list1 = list1->next;
      } else {
        prev->next = list2;
        list2 = list2->next;
      }
      prev = prev->next;
    }
    prev->next = (list1 == NULL) ? list2 : list1;
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
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(1);
  ListNode* node5 = new ListNode(3);
  ListNode* node6 = new ListNode(4);
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;

  node4->next = node5;
  node5->next = node6;
  node6->next = NULL;
  traverseNode(node1);
  traverseNode(node4);

  ListNode* output;
  Solution sol;
  output = sol.mergeTwoLists(node1, node4);
  traverseNode(output);

  return 0;
}