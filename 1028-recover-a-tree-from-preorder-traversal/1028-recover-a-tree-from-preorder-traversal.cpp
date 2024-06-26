class Solution {
    bool isDigit(char c){
        return c>='0'&&c<='9';
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        unordered_map<int,TreeNode*> m;
        
        int i = 0;
        while(i<traversal.size()){
            int d = 0;
            while(i<traversal.size() && traversal[i]=='-'){
                d++;
                i++;
            }
            string s = "";
            while(i<traversal.size() && isDigit(traversal[i])){
                s+= traversal[i];
                i++;
            }
            int val = stoi(s);
            TreeNode* node = new TreeNode(val);
            if(d>0){
                TreeNode* p = m[d-1];
                if(p->left==NULL){
                    p->left = node;
                }
                else{
                    p->right = node;
                }
            }
            m[d] = node;
        }
        
        return m[0];
    }
};