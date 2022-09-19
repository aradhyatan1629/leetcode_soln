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
        int size=0;
        ListNode *temp=head;
        ListNode *prev=temp;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        if(size==1)
        {
            return NULL;
        }
        int x=0;
        temp=head;
        while(x!=size/2)
        {
            prev=temp;
            temp=temp->next;
            x++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete(temp);
        return head;
    }
};