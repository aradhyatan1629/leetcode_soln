class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int mx=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)sum-=1;
            else sum+=1;
            if(sum==0)
                mx=max(mx,i+1);
            if(m.find(sum)==m.end())
                m[sum]=i;
            else
                mx=max(mx,i-m[sum]);
        }
        return mx;
    }
};



/*

0,0,1,1,0,1
-1,-2,-1,0,0,1

0,0,1,1,1,0,0,0
-1,-2,-1,0,1,0,-1,-2


*/