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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp = head;
        int sz = 0;
        while(temp){
            sz++;
            temp = temp->next;
        }
        vector<ListNode*> ans;
        if(sz <= k){
            ListNode *temp1 = head;
            while(temp1){
                ans.push_back(temp1);
                ListNode *curr = temp1;
                temp1=temp1->next;
                curr->next = NULL;
                k--;
            }
            while(k){
                ans.push_back(NULL);
                k--;
            }
            return ans;
        }
        int d = sz/k;
        int extra = sz%k;
        // cout<<"sz "<<sz<<"d "<<d<<endl;
        temp = head;
        while(temp){
            // vector<ListNode*> v;
            int t = d;
            if(extra>0)t++,extra--;
            ListNode *newHead = temp;
            ListNode *temp2 = NULL;
            while(temp->next && t!=1){
                // v.push_back(temp);
                temp = temp->next;
                t--;
            }
            ListNode *curr = temp;
            temp=temp->next;
            curr->next = NULL;
            ans.push_back(newHead);
            // if(temp)cout<<"val "<<newHead->val<<" "<<temp->val<<endl;
        }
        return ans;
    }
};