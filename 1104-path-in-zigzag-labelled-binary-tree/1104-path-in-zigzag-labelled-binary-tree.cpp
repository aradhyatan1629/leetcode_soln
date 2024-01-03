class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int height = log2(label);
        ans.push_back(label);
        
        while(height!=0)
        {
            int start = pow(2,height);
            int end = (pow(2,height) * 2) - 1;
            int x = (start + end) - label;
            int parent = x/2;
            ans.push_back(parent);
            height--;label=parent;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
