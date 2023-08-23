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
    //iterative postorder using 1 stack
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        stack<TreeNode*> st;
        vector<int> v;
        TreeNode *curr = root;
        while(curr or !st.empty())
        {
            if(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode *temp = st.top()->right;
                if(temp==NULL)
                {
                    temp = st.top();
                    st.pop();
                    v.push_back(temp->val);
                    while(!st.empty() and temp==st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        v.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return v;
    }
};