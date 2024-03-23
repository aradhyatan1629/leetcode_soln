/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p=NULL,*q=NULL,*r=NULL;
        p=head;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return head;
    }
    
    void reorderList(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *head2 = reverseList(slow->next);
        slow->next = NULL;
        while(head and head2)
        {
            ListNode *t1=head,*t2=head2;
            head=head->next;
            head2=head2->next;
            t1->next = t2;
            t2->next = head;
        }
    }
};

/*

1 2 3 4 5 6
1 6 2 5 3 4

*/