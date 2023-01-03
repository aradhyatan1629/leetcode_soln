class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        int mx=0;
        if(nums.size()==0)
        {
            return 0;
        }
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=true;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i]-1)!=m.end())   //that number cannot be start of sequence
            {
                m[nums[i]]=false;
            }
        }
        for(auto x:m)
        {
            if(x.second==true)
            {
                int t=x.first;
                int len=0;
                while(m.find(t)!=m.end())
                {
                    len++;
                    t++;
                }
                mx=max(mx,len);
            }
        }
        return mx;
    }
};