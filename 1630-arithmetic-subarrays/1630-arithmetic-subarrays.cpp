class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        vector<int> t;
        for(int i=0;i<l.size();i++)
        {
            int x=l[i];
            int y=r[i];
            int flag=1;
            for(int i=x;i<=y;++i)
            {
                t.push_back(nums[i]);
            }
            sort(t.begin(),t.end());
            for(int i=0;i<t.size()-1;i++)
            {
                if(t[i+1]-t[i]!=t[1]-t[0])
                {
                    flag=-1;
                    ans.push_back(false);
                    break;
                }
            }
            if(flag==1)
            {
                ans.push_back(true);
            }
            t.clear();
        }
        return ans;
    }
};