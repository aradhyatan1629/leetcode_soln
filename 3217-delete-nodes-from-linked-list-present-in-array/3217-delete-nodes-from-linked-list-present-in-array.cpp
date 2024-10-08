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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]] = 1;
        
        ListNode *prev=NULL,*curr=head;
        
        while(curr)
        {
            if(m.find(head->val)!=m.end())
            {
                while(head && m.find(head->val)!=m.end())
                {
                    head = head->next;
                    curr = head;
                }
            }
            else if(m.find(curr->val)!=m.end())
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};