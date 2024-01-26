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
    vector<int> NGR(vector<int> &v)
    {
        stack<int> st;
        vector<int> ans;
        int n=v.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=v[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode *temp=head,*prev=NULL;
        vector<int> v;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> ngr = NGR(v);
        int i=0,n=v.size();
        while(i<n-1 and ngr[i]!=-1)
        {
            i++;
            head=head->next;
        }
        temp=head,prev=temp;
        while(i<n-1)
        {
            if(ngr[i] != -1)
            {
                prev->next = temp->next;
                temp=temp->next;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
            i++;
        }
        return head;
    }
};