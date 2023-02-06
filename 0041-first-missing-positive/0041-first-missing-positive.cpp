class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x:nums)
        {
            st.insert(x);
        }
        int i=1;
        int ans=0;
        while(true)
        {
            if(st.find(i)==st.end())
            {
                ans=i;
                break;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};