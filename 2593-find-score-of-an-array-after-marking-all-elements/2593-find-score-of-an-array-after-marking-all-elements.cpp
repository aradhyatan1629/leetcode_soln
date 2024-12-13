class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        
        unordered_map<int,int> m;
        long long ans = 0;
        while(m.size() != n){
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(m.find(ind) == m.end()){
                ans += ele;
                m[ind] = 1;
                if(ind-1 >= 0)m[ind-1] = 1;
                if(ind+1 < n)m[ind+1] = 1;
            }
        }
        return ans;
        
    }
};