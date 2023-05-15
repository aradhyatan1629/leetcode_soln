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
    
    
    
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode *temp=head;
        ListNode *temp1=NULL,*temp2=NULL;
        int n1=0,n2=0;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        if(n==1)
        {
            return head;
        }
        temp=head;
        
        int x=1;
        while(temp!=NULL)
        {
            if(x==k)
            {
                n1=temp->val;
                temp1=temp;
            }
            if(x==n-k+1)
            {
                n2=temp->val;
                temp2=temp;
            }
            x++;
            temp=temp->next;
        }
        
        temp1->val = n2;
        temp2->val = n1;
        return head;
    }
};