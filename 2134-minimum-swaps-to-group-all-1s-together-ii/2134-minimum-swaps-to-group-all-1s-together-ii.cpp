class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totOne = count(nums.begin(),nums.end(),1);
        if(totOne == 0)
            return 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        int i=0,j=0;
        n=nums.size();
        int cnt0 = 0;
        int mn = INT_MAX;
        while(j<n)
        {
            if(nums[j]==0)cnt0++;
            if(j-i+1<totOne)
            {
                j++;
            }
            else if(j-i+1==totOne)
            {
                mn = min(mn,cnt0);
                if(nums[i]==0)cnt0--;
                i++,j++;
            }
        }
        return mn;
    }
};

