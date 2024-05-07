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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *p=NULL,*q=NULL,*r=NULL;
        p=head;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        head = q;
        return head;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        ListNode *dummy = new ListNode(0),*newHead = dummy;
        ListNode *temp = head;
        int carry = 0;
        while(temp || carry)
        {
            int sum = 0;
            if(temp)
            {
                sum = (temp->val * 2);
                temp = temp->next;
            }
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            ListNode *newNode = new ListNode(sum);
            dummy->next = newNode;
            dummy = dummy->next;
        }
        newHead = newHead->next;
        newHead = reverseList(newHead);
        return newHead;
    }
};