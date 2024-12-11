class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int idx1=0,idx2=0;
        int ans=0;
        while(idx1<n && idx2<n){
            if(nums[idx2]-nums[idx1]<=2*k){
                idx2++;
                ans=max(ans,idx2-idx1);
            }else{
                idx1++;
                ans=max(ans,idx2-idx1);
            }
        }
        return ans;
    }
};