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
            q->next=r;
        }
        head=q;
        return head;
    }
    
    ListNode *getKthNode(ListNode *temp,int k)
    {
        k-=1;
        while(temp and k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prevLast = NULL;
        while(temp!=NULL)
        {
            ListNode *kthNode = getKthNode(temp,k);
            if(kthNode == NULL)  // if we dont have any group of k size
            {
                if(prevLast)
                    prevLast->next=temp;
                break;
            }
            ListNode *nextNode = kthNode->next;
            kthNode->next=NULL;
            reverseList(temp);
            if(temp == head) //means this is our first group
            {
                head=kthNode;
            }
            else
            {
                prevLast->next = kthNode;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};