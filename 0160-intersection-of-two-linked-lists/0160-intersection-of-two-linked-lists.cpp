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
        ListNode *temp1=headA,*temp2=headB;
        while(temp1)
        {
            while(temp2)
            {
                if(temp1 == temp2)
                    return temp1;
                temp2=temp2->next;
            }
            temp1=temp1->next;
            temp2=headB;
        }
        return NULL;
    }
};

// tc - O(n^2) sc - O(1)
