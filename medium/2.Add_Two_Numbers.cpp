#include <math.h>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1!=NULL||l2!=NULL||sum>0)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            (*node)=new ListNode(sum%10);
            sum/=10;
            node=&((*node)->next);
        }        
        return l3;
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
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(4);
  ListNode* node3 = new ListNode(0);
  ListNode* node4 = new ListNode(5);
  ListNode* node5 = new ListNode(6);
  ListNode* node6 = new ListNode(0);
  node1->next = node2;
  node2->next = node3;
  node3->next = NULL;
  node4->next = node5;
  node5->next = node6;
  node6->next = NULL;
  traverseNode(node3);
  traverseNode(node6);

  Solution sol;
  ListNode* output;
  output = sol.addTwoNumbers(node3, node6);
  traverseNode(output);
  return 0;
}