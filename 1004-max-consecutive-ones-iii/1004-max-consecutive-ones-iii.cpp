class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        int cnt1=0,cnt0=0,ans=0;
        
        while(j<n)
        {
            if(nums[j]==1)
            {
                cnt1++;
            }
            if(j-i+1-cnt1 > k)
            {
                // cout<<"hi "<<endl;
                while(j-i+1-cnt1 > k)
                {
                    if(nums[i]==1)
                    {
                        cnt1--;
                    }
                    i++;
                    // cout<<"i "<<endl;
                }
            }
            ans = max(ans,j-i+1);
            // cout<<ans<<endl;
            j++;
        }
        return ans;
    }
};


/*
Intuition - Same intuition as ques 424 
*/