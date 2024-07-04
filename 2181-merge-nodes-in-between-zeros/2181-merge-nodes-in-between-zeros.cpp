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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head;
        long long sum = 0;
        ListNode *ansHead = new ListNode(-1);
        ListNode *temp1 = ansHead;
        
        while(temp)
        {
            if(temp->val == 0)
            {
                temp = temp->next;
            }
            while(temp!=NULL && temp->val!=0)
            {
                sum += temp->val;
                temp = temp->next;
            }
            ListNode *newNode = new ListNode(sum);
            if(sum!=0)
                temp1->next = newNode;
            temp1 = temp1->next;
            sum = 0;
        }
        return ansHead->next;
    }
};