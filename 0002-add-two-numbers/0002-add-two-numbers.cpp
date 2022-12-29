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
//         Using vector to reverse and stack for additon
        stack<int> st1,st2;
        vector<int> v1,v2,ans;
        ListNode *temp1=l1,*temp2=l2;
        while(temp1!=NULL)
        {
            v1.push_back(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            v2.push_back(temp2->val);
            temp2=temp2->next;
        }
        temp1=l1,temp2=l2;
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        for(auto x:v1)
        {
            st1.push(x);
        }
        for(auto x:v2)
        {
            st2.push(x);
        }
        int carry=0,sum=0;
        while(st1.size()!=0 or st2.size()!=0 or carry!=0)
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
                ans.push_back(sum%10);
            }
            else
            {
                ans.push_back(sum);
                carry=0;
            }
            sum=0;
        }
        ListNode *l = new ListNode;
        ListNode *temp = l;
        for(int i=0;i<ans.size();i++)
        {
            ListNode *ptr = new ListNode(ans[i]);
            temp->next=ptr;
            temp=temp->next;
        }
        return l->next;
    }
};


