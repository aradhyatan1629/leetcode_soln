class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        vector<int> ans;
        int i=0,j=0;
        int disc=0;
        for(i=0;i<p.size();i++)
        {
            disc=0;
            for(j=i+1;j<p.size();j++)
            {
                if(p[j]<=p[i])
                {
                    disc = p[j];
                    break;
                }
            }
            ans.push_back(p[i]-disc);
        }
        return ans;
    }
};