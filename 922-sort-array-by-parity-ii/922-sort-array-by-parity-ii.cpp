class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        vector<int> ans(nums.size(),0);
        for(auto x:nums)
        {
            if(x%2==0)
            {
                even.push_back(x);
            }
            else
            {
                odd.push_back(x);
            }
        }
        int j=0;
        for(int i=0;i<ans.size();i+=2)
        {
            ans[i] = even[j++];
        }
        j=0;
        for(int i=1;i<ans.size();i+=2)
        {
            ans[i] = odd[j++];
        }
        return ans;
    }
};