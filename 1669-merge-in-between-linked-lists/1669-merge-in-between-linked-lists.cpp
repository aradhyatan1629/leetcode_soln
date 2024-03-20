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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int ind=0;
        ListNode *prev=NULL,*curr=list1;
        ListNode *t1=NULL,*t2=NULL;
        while(curr)
        {
            if(ind==a)
                t1=prev;
            else if(ind==b+1)
                t2=prev;
            prev=curr;
            curr=curr->next;
            ind++;
        }
        ListNode *temp=list2;
        while(temp->next!=NULL)
            temp=temp->next;
        t1->next=list2;
        temp->next=t2->next;
        return list1;
    }
};