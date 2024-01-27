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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)return head;
        int n=0;
        ListNode *temp=head;
        while(temp)
        {
            n++;
            temp=temp->next;
        }
        k%=n;
        if(k==0)return head;
        head=reverseList(head);
        temp=head;
        int t=1;
        while(t<k)
        {
            t++;
            temp = temp->next;
        }
        ListNode *temp2 = temp->next;
        temp->next=NULL;
        ListNode *newHead1 = reverseList(head);
        ListNode *newHead2 = reverseList(temp2);
        head->next=newHead2;
        return newHead1;
    }
};

// Using same concept as rotate array 









