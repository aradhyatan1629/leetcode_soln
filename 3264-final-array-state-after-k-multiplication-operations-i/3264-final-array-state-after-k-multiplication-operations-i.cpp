class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<int> ans;
        for(auto x:nums)ans.push_back(x);
        while(k--){
            int x = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            ans[ind] = x*multiplier;
            pq.push({ans[ind],ind});
        }
        return ans;
    }
};