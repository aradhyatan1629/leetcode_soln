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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0,t=0;
        ListNode *temp=head;
        while(temp)
        {
            sz++;
            temp=temp->next;
        }
        int target = sz-n;
        ListNode *curr=head;
        ListNode *prev=head;
        
        if(sz==1 and n==1)
        {
            return NULL;
        }
        else if(target==0)
        {
            temp = head->next;
            head->next=NULL;
            head=temp;
            return head;
        }
        
        while(t<target)
        {
            prev=curr;
            curr=curr->next;
            t++;
        }
        prev->next = curr->next;
        curr->next=NULL;
        delete(curr);
        return head;
    }
};