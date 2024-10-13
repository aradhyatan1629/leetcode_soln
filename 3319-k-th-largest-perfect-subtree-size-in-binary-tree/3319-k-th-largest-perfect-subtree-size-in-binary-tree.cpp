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
    
    void getSize(TreeNode *root,int &sz){
        if(root == NULL)
            return;
        sz++;
        getSize(root->left,sz);
        getSize(root->right,sz);
    }
    
    int height(TreeNode *root){
        if(root == NULL)
            return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return 1 + max(leftH,rightH);
    }
    
    bool isPerfect(TreeNode *root,int h,int level){
        if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL){
            return h == level;
        }
        
        if(root->left == NULL || root->right == NULL){
            return false;
        }
        
        bool l = isPerfect(root->left,h,level+1);
        bool r = isPerfect(root->right,h,level+1);
        return l && r;
    }
    
    void solve(TreeNode *root,vector<int> &v){
        if(root == NULL)
            return;
        int h = height(root);
        h--;
        // cout<<"root "<<root->val<<" height "<<h<<endl;
        if(isPerfect(root,h,0)){
            // cout<<" yes "<<root->val<<endl;
            int sz = 0;
            getSize(root,sz);
            v.push_back(sz);
        }
        solve(root->left,v);
        solve(root->right,v);
    }
    
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> v;
        solve(root,v);
        sort(v.begin(),v.end(),greater<int>());
        if(k > v.size())
            return -1;
        return v[k-1];
    }
};