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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return NULL;
        int cnt=0;
        ListNode *temp=head,*prev=NULL;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
        int mid = cnt/2;
        int i=0;
        temp=head,prev=temp;
        while(i<mid)
        {
            prev=temp;temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        return head;
    }
};