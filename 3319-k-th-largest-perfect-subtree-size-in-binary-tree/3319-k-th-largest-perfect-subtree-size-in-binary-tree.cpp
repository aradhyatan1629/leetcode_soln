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
    bool check(TreeNode *root,int &subSize){
        int lvl = 1;
        queue<TreeNode*> q;
        q.push(root);
        unordered_set<int> s;
        
        while(!q.empty()){
            int sz = q.size();
            subSize += q.size();
            for(int i=0;i<sz;i++){
                TreeNode *node = q.front();
                q.pop();
                if(node->left == NULL && node->right == NULL){
                    if(s.size() == 0)
                        s.insert(lvl);
                    else if(lvl != *s.begin())
                        return false;
                }
                else if(node->left == NULL || node->right == NULL)
                    return false;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
            lvl++;
        }
        return s.size() == 1;
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                TreeNode *node = q.front();
                q.pop();
                int sz = 0;
                if(check(node,sz)){
                    v.push_back(sz);
                }
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        
        sort(v.begin(),v.end(),greater<int>());
        if(k > v.size())
            return -1;
        return v[k-1];
    }
};