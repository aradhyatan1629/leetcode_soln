class Solution {
public:
    int numberOfBeams(vector<string>& banks) {
        int ans = 0;
        for(int i=0;i<banks.size()-1;i++)
        {
            int t = count(banks[i].begin(),banks[i].end(),'1');
            for(int j=i+1;j<banks.size();j++)
            {
                int cnt1 = count(banks[j].begin(),banks[j].end(),'1');
                if(cnt1>0)
                {
                    ans+=t*cnt1;
                    break;
                }
            }
        }
        return ans;
    }
};