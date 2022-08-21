class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        int cnt=0;
        int t=c;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]<=c)
            {
                c=c-p[i];
                cnt++;
            }
            else
            {
                c=t;
                cnt+=i;
                cnt+=i+1;
                c=c-p[i];
            }
        }
        return cnt;
    }
};