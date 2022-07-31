class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int j=1;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(nums[nums.size()-i-1]);
            int sum1 = accumulate(nums.begin(),nums.end()-j,0);
            int sum2 = accumulate(ans.begin(),ans.end(),0);
            j++;
            if(sum2>sum1)
            {
                break;
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};


/*{3,4,8,9,10}*/