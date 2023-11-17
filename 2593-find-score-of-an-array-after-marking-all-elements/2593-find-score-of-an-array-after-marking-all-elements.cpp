class Solution {
public:
    long long findScore(vector<int>& nums) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        long long score = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
                
        while(!pq.empty())
        {
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if(m[index]==1)
            {
                continue;
            }
            score+=val;
            m[index]=1;
            if(index-1>=0)
                m[index-1]=1;
            if(index+1<nums.size())
                m[index+1]=1;
        }
        return score;
    }
};