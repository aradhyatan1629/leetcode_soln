class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        long long ans = 0;
        while(k--){
            ans += pq.top();
            int x = ceil(pq.top()/3.0);
            pq.pop();
            pq.push(x);
        }
        return ans;
    }
};