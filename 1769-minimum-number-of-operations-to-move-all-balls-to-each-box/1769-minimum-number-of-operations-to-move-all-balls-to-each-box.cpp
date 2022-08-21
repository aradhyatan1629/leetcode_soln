class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int op=0;
        for(int i=0;i<boxes.size();i++)
        {
            op=0;
            for(int j=0;j<boxes.size();j++)
            {
                if(i!=j and boxes[j]=='1')
                {
                    op+=abs(i-j);
                }
            }
            ans.push_back(op);
        }
        return ans;
    }
};