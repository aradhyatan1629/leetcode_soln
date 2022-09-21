class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        int indexmn=-1,indexmx=-1;
        int n=nums.size();
        if(n==1)
        {
            return 1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mn)
            {
                indexmn=i;
            }
            if(nums[i]==mx)
            {
                indexmx=i;
            }
        }
        int dfmn=0,dfmx=0,dbmn=0,dbmx=0;
        int frontfront=0,backback=0,frontback=0;
        dfmn=indexmn+1;
        dfmx=indexmx+1;
        dbmn=n-indexmn;
        dbmx=n-indexmx;
        frontfront=max(dfmn,dfmx);
        backback=max(dbmn,dbmx);
        frontback=min(dfmn,dbmn)+min(dfmx,dbmx);
        int ans=min(frontfront,backback);
        int res=min(ans,frontback);
        return res;
    }
};