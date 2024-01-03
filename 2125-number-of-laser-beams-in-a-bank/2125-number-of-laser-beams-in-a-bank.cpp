class Solution {
public:
    int numberOfBeams(vector<string>& banks) {
        int ans = 0;
        int prev = 0;
        for(int i=0;i<banks.size();i++)
        {
            int cnt1=0;
            for(int j=0;j<banks[i].size();j++)
            {
                if(banks[i][j] == '1')
                    cnt1++;
            }
            ans += prev*cnt1;
            prev = (cnt1>0) ? cnt1 : prev;
        }
        return ans;
    }
};