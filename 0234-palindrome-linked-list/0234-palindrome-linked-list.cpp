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
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast->next and fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *first=head,*second=reverseList(slow->next);
        while(second)
        {
            if(first->val != second->val)
                return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};


