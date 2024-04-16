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
        int cnt = 0;
        ListNode *temp = head;
        while(temp)
        {
            cnt++;
            temp = temp->next;
        }
        int t = cnt-n;
        if(t==0)
        {
            head = head->next;
            return head;
        }
        temp = head;
        ListNode *prev = temp;
        int ind = 0;
        while(ind != t)
        {
            prev = temp;
            temp=temp->next;
            ind++;
        }
        prev->next = temp->next;
        temp->next = NULL;
        return head;
    }
};