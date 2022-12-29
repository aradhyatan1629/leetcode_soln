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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         Using stack for additon and reversing the answer list using sliding pointers
        stack<int> st1,st2;
        ListNode *temp1=l1,*temp2=l2;
        ListNode *l=new ListNode;   //list which contains our answer
        ListNode *temp=l;
        while(temp1!=NULL)
        {
            st1.push(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            st2.push(temp2->val);
            temp2=temp2->next;
        }
        int sum=0,carry=0;
        while(st1.size() or st2.size() or carry)
        {
            if(st1.size()!=0)
            {
                sum+=st1.top();
                st1.pop();
            }
            if(st2.size()!=0)
            {
                sum+=st2.top();
                st2.pop();
            }
            sum+=carry;
            if(sum>=10)
            {
                carry=sum/10;
                ListNode *ptr = new ListNode(sum%10);
                temp->next=ptr;
                temp=temp->next;
            }
            else
            {
                ListNode *ptr = new ListNode(sum);
                temp->next=ptr;
                temp=temp->next;
                carry=0;
            }
            sum=0;
        }
        temp=l;
        l=l->next;
        temp->next=NULL;
        temp=l;
        ListNode *p=l,*q=NULL,*r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        l=q;
        return l;
    }
};