class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(x==total)
        {
            return n;
        }
        if(x>total)
        {
            return -1;
        }
        int i=0,j=0,currsum=0,ans=-1;
        while(j<n)
        {
            currsum+=nums[j];
            if(currsum==total-x)
            {
                ans = max(ans,j-i+1);
            }
            else if(currsum>total-x)
            {
                while(currsum>total-x)
                {
                    currsum-=nums[i];
                    i++;
                }
                if(currsum==total-x)
                {
                    ans=max(ans,j-i+1);
                }
            }
            j++;
        }
        if(ans==-1)
        {
            return -1;
        }
        return n-ans;
    }
};