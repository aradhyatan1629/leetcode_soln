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
    
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode *temp=head->next,*prev=head;
        int mx=head->val;
        while(temp)
        {
            if(temp->val >= mx)
            {
                mx = temp->val;
                prev=temp;
                temp=temp->next;
            }
            else
            {
                prev->next=temp->next;
                temp=temp->next;
            }
        }
        head=reverseList(head);
        return head;
    }
};