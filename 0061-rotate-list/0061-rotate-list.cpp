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
        ListNode *temp = head;
        vector<int> v1,v2;
        while(temp)
        {
            v1.push_back(temp->val);
            temp = temp->next;
        }
        k=k%v1.size();
        v2.resize(v1.size(),0);
        for(int i=0;i<v1.size();i++)
        {
            int idx = (i+k)%v1.size();
            v2[idx] = v1[i];
        }
        int i=0;temp=head;
        while(temp)
        {
            temp->val=v2[i++];
            temp=temp->next;
        }
        return head;
    }
};