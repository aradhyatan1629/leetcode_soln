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
        int m=0,n=0;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1 or temp2)
        {
            if(temp1)
            {
                m++;
                temp1=temp1->next;
            }
            if(temp2)
            {
                n++;
                temp2=temp2->next;
            }
        }
        temp1=headA,temp2=headB;
        int diff = m-n;
        if(diff>0)
        {
            while(diff)
            {
                temp1=temp1->next;
                diff--;
            }
        }
        else if(diff<0)
        {
            int t=abs(diff);
            while(t)
            {
                temp2=temp2->next;
                t--;
            }
        }
        while(temp1!=temp2)
        {
            if(temp1==temp2)
                return temp1;
            if(temp1)temp1=temp1->next;
            if(temp2)temp2=temp2->next;
        }
        return temp1; 
    }
};
//O(m+n)




