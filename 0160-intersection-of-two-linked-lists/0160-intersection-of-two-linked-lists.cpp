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
        unordered_map<ListNode*,int> m;
        ListNode *temp1=headA,*temp2=headB;
        while(temp1!=NULL)
        {
            m[temp1]=1;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            if(m[temp2]==1)
                return temp2;
            temp2=temp2->next;
        }
        return NULL;
    }
};

//tc - O(2n) sc - O(n) 