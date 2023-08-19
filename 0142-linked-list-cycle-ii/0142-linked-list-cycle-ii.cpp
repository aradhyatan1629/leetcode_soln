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
    //O(n) O(1)
    //1) Find collision point
    //2) Find the starting point of loop
    
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *entry=head;
        
        while(fast->next and fast->next->next) //finding the collision point
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(slow!=entry)    //finding the starting point of the loop
                {
                    slow=slow->next;
                    entry=entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};