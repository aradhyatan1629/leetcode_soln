class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> q;
        for(int i=0;i<n;i++)
            q.push(i);
        int tm = 0;
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();
            if(tickets[ind]!=0)
            {
                tm++;tickets[ind]--;
                if(tickets[ind]==0 and k==ind)
                    return tm;
                q.push(ind);
            }
        }
        return -1;
    }
};