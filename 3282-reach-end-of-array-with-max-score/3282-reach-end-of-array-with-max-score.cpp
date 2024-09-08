class Solution {
public:
    vector<int> ngr(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> v;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            if(st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top());
            st.push(i);
        }
        return v;
    }
    
    long long findMaximumScore(vector<int>& nums) {
        vector<int> v = ngr(nums);
        reverse(v.begin(),v.end());
        long long ans = 0;
        
        int ind = 0;
        
        while(ind<v.size()-1){
            if(v[ind] == -1)
                break;
            ans += (long long)(v[ind]-ind) * nums[ind];
            ind = v[ind];
        }
        if(ind!=v.size()-1){
            ans += (long long)(v.size()-1-ind)*nums[ind];
        }
        return ans;
    }
};