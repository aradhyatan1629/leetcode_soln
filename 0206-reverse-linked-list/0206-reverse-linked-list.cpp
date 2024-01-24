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
    void reverse(ListNode *p,ListNode *q,ListNode *&head)
    {
        if(p!=NULL)
        {
            reverse(p->next,p,head);
            p->next=q;
        }
        else
        {
            head = q;
        }
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *p=NULL,*q=NULL;
        p=head;
        reverse(p,q,head);
        return head;
    }
};

//Using sliding pointers (RECURSIVE) O(n) and O(1)
//We are reversing the links on backtracking