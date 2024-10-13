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
    bool check(TreeNode *root, int &subSize) {
    if (!root) return false;

    int lvl = 0; // Initialize level outside
    queue<TreeNode*> q;
    q.push(root);
    int leafLevel = -1;
    
    while (!q.empty()) {
        int sz = q.size();
        subSize += sz; // Add current level size to subSize

        for (int i = 0; i < sz; i++) {
            TreeNode *node = q.front();
            q.pop();

            if (node->left == NULL && node->right == NULL) {
                // Leaf node case
                if (leafLevel == -1)
                    leafLevel = lvl;
                else if (lvl != leafLevel)
                    return false;
            } else if (node->left == NULL || node->right == NULL) {
                // Non-leaf node must have both children
                return false;
            }
            
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        lvl++; // Move to the next level after processing the current one
    }
    return true;
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