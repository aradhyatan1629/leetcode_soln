class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> s1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                set<long long> s2;
                for(int k=j+1;k<n;k++)
                {
                    long long sum = nums[i]+nums[j];
                    sum+=nums[k];
                    long long fourth = target-sum;
                    if(s2.find(fourth)!=s2.end())
                    {
                        vector<int> v = {nums[i],nums[j],nums[k],(int)(fourth)};
                        sort(v.begin(),v.end());
                        s1.insert(v);
                    }
                    s2.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(s1.begin(),s1.end());
        return ans;
    }
};

// tc - O(n^3 * log(M)) , M is the number of unique quadruples 