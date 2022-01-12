#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode *next) : val(x), next(next){};
};

class Solution {
  int countNode(ListNode *ptr) {
    int total;
    while (ptr != NULL) {
      ptr = ptr->next;
      total++;
    }
    return total;
  }

 public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int delete_index = countNode(head) - n;
    int ctr = 1, nodectr;
    ListNode *temp, *prev;
    if (head == NULL) {
      cout << "Empty";
    } else {
      nodectr = countNode(head);
      if (delete_index > nodectr) {
        cout << "out of the space";
      }
      if (delete_index > 1 && delete_index < nodectr) {
        temp = prev = head;
        while (ctr < delete_index) {
          prev = temp;
          temp = temp->next;
          ctr++;
        }
        prev->next = temp->next;
        free(temp);
      }
    }
    return head;
  }
};

int main() {
  ListNode *head;
  ListNode c;
  c.next = NULL;
  head = new node;

  return 0;
}