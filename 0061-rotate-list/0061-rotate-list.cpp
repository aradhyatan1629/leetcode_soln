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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)return head;
        int n=0;
        ListNode *temp = head,*tail=NULL;
        while(temp)
        {
            n++;
            tail = temp;
            temp = temp->next;
        }
        k%=n;
        if(k==0)return head;
        tail->next = head;
        int t=1;temp=head;
        while(t<n-k)
        {
            t++;
            temp=temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

// O(n) O(1)