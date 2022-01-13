#include <iostream>
#include <unordered_set>
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
  bool hasCycle(ListNode* head) {
    ListNode* slow;
    slow = head;
    ListNode* fast;
    fast = head;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    return false;
  }
};

void traverseNode(ListNode* head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
}

int main() {
  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(2);
  ListNode* node3 = new ListNode(0);
  ListNode* node4 = new ListNode(-4);
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node2;

  Solution sol;
  cout << (sol.hasCycle(node1) ? "true" : "false") << endl;

  return 0;
}