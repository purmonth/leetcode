#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void traverseNode(ListNode* head)
{
    while(head!=NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head;
        int counter = 0;
        cout << endl;
        while(p != NULL){
            p = p->next;
            counter ++;
        }
        counter /= 2;
        while(counter -- > 0){
            head = head->next;
        }
        return head;
    }
};

int main()
{
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    traverseNode(node1);

    Solution sol;

    ListNode* newHead = sol.middleNode(node1);
    
    traverseNode(newHead);

    return 0;
}