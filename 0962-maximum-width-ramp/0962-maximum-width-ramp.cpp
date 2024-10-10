class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.empty() || nums[i] <= nums[st.top()]){
                st.push(i);
            }
        }
        int mx = 0;
        for(int j=nums.size()-1;j>=0;j--){
            while(!st.empty() && nums[st.top()] <= nums[j]){
                mx = max(mx,j-st.top());
                st.pop();
            }
        }
        return mx;
    }
};

/*

create a decreasing stack

6,0,8,2,1,5

0
6




*/