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
    int gcd(int a,int b){
        while(a>0 && b>0){
            if(a>b){
                a = a%b;
            }
            else{
                b = b%a;
            }
        }
        if(a == 0)return b;
        return a;
    }
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;
        ListNode *nextNode = curr->next;
        
        while(nextNode){
            int val = gcd(curr->val,nextNode->val);
            ListNode *temp = new ListNode(val);
            curr->next = temp;
            temp->next = nextNode;
            curr = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};