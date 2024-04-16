/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1=0,len2=0;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1 || temp2)
        {
            if(temp1)
                len1++,temp1=temp1->next;
            if(temp2)
                len2++,temp2=temp2->next;
        }
        int diff = abs(len1-len2);
        temp1=headA,temp2=headB;
        if(len1>len2)
        {
            while(diff)
            {
                diff--;
                temp1=temp1->next;
            }
        }
        else
        {
            while(diff)
            {
                diff--;
                temp2=temp2->next;
            }
        }
        while(temp1 && temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
        
    }
};