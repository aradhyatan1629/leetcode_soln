class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
        vector<int> v;
        int len = 1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] >= nums[i+1]){
                v.push_back(len);
                len = 1;
            }
            else{
                len++;
            }
        }
        
        v.push_back(len);
        
        if(v.size() == 1)
            return v[0]/2;
        
        // for(auto x:v)cout<<x<<" ";

        int ans = INT_MIN;
        for(int i=0;i<v.size()-1;i++){
            int mn = min(v[i],v[i+1]);
            int half = v[i]/2;
            ans = max(ans,max(half,mn));
        }
        
        ans = max(ans,v[v.size()-1]/2);
        
        return ans;
    }
};