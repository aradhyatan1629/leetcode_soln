class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<k)
            {
                if(m[k-nums[i]]>0)
                {
                    cnt++;
                    m[k-nums[i]]--;
                }
                else
                {
                    m[nums[i]]++;
                }
            }
        }
        return cnt;
    }
};

