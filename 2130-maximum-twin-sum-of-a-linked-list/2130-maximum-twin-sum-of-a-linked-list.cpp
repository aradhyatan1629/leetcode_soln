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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        int mx = INT_MIN;
        for(int i=0;i<=(v.size()/2)-1;i++)
        {
            int a = v[i];
            int b = v[v.size()-i-1];
            mx = max(mx,(a+b));
        }
        return mx;
    }
};