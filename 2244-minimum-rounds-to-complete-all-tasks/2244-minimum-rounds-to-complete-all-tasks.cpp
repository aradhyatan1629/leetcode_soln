class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(int i=0;i<tasks.size();i++)
        {
            m[tasks[i]]++;
        }
        int ans=0;
        for(auto x:m)
        {
            if(x.second==1)
            {
                return -1;
            }
            else if(x.second%3==0)
            {
                ans+=x.second/3;
            }
            else
            {
                ans+=x.second/3+1;
            }
        }
        return ans;
    }
};