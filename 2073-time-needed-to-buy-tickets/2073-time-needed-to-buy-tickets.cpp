class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int c=0;
        while(true)
        {
            for(int i=0;i<tickets.size();i++)
            {
                if(tickets[i]==0)
                {
                    continue;
                }
                tickets[i]--;
                c++;
                if(tickets[k]==0)
                {
                    return c;
                }
            }
        }
        return 0;
    }
};