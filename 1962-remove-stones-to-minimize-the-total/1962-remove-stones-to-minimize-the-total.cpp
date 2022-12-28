class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto x:piles)
        {
            pq.push(x);
        }
        while(k--)
        {
            int x = pq.top()-floor(pq.top()/2);
            pq.pop();
            pq.push(x);
        }
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};


// 9 5 4 
