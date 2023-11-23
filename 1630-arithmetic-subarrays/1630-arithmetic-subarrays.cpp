class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++)
        {
            vector<int> t;
            for(int j=l[i];j<=r[i];j++)
                t.push_back(nums[j]);
            sort(t.begin(),t.end());
            bool flag=true;
            for(int j=1;j<t.size();j++)
            {
                if(t[j]-t[j-1] != t[1]-t[0])
                {
                    flag=false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};