class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long score=0;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k--)
        {
            score+=pq.top();
            int x = ceil(double(pq.top())/3);
            pq.pop();
            pq.push(x);
        }
        return score;
    }
};