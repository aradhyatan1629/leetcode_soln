class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        for(int i=0;i<piles.size();i++)
        {
            q.push(piles[i]);
        }
        while(k--)
        {
            int remove=q.top()/2;
            int left=q.top()-remove;
            q.pop();
            q.push(left);
        }
        int ans=0;
        while(!q.empty())
        {
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};