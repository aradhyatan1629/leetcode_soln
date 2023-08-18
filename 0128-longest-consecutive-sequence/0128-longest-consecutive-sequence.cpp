class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int mx=1;
        for(auto x:st)
        {
            if(st.find(x-1)==st.end())
            {
                int cnt=1;
                int t = x+1;
                while(st.find(t)!=st.end())
                {
                    cnt++;
                    t++;
                }
                mx = max(mx,cnt);
            }
        }
        return mx;
    }
};