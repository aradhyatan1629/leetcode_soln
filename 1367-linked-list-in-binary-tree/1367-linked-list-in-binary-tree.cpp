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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode *root,ListNode *head)
    {
        if(head==NULL)
            return true;
        if(root==NULL)
            return false;
        if(head->val != root->val)
            return false;
        bool left = solve(root->left,head->next);
        bool right = solve(root->right,head->next);
        if(left or right)
            return true;
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==NULL)
            return false;
        
        return solve(root,head) or isSubPath(head,root->left) or isSubPath(head,root->right);
    }
};