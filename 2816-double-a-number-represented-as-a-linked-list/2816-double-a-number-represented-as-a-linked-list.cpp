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
    void reverseList(ListNode *&head)
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
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        reverseList(head);
        ListNode *temp = head;
        int carry=0;
        while(temp or carry)
        {
            int sum=0;
            if(temp)
            {
                sum = (temp->val)*2;
                temp=temp->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode *t = new ListNode(sum%10);
            curr->next = t;
            curr=curr->next;
        }
        dummy=dummy->next;
        reverseList(dummy);
        return dummy;   
    }
};