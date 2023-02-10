class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                nums[i]=0;
            }
            else
            {
                nums[i]=1;
            }
        }
        for(int i=1;i<nums.size();i++)
        {
            nums[i]=nums[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(nums[i]==k)
            {
                cnt++;
            }
            if(m[nums[i]-k]>0)
            {
                cnt+=m[nums[i]-k];
            }
        }
        return cnt;
    }
};

