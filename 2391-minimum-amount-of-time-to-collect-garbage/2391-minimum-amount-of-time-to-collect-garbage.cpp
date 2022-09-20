class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=-1,m=-1,p=-1;
        int ans=0;
        int n=garbage.size();
        for(int i=n-1;i>=0;i--)
        {
            if(find(garbage[i].begin(),garbage[i].end(),'G')!=garbage[i].end())
            {
                g=max(i,g);
            }
             if(find(garbage[i].begin(),garbage[i].end(),'M')!=garbage[i].end())
            {
                m=max(i,m);
            }
             if(find(garbage[i].begin(),garbage[i].end(),'P')!=garbage[i].end())
            {
                p=max(i,p);
            }
        }
        string s;
        for(int i=0;i<garbage.size();i++)
        {
            s+=garbage[i];
        }
        int gcnt=0,mcnt=0,pcnt=0;
        gcnt=count(s.begin(),s.end(),'G');
        mcnt=count(s.begin(),s.end(),'M');
        pcnt=count(s.begin(),s.end(),'P');
        if(gcnt!=0)
        {
            int sum=accumulate(travel.begin(),travel.begin()+g,0);
            ans+=sum+gcnt;
        }
        if(mcnt!=0)
        {
            int sum=accumulate(travel.begin(),travel.begin()+m,0);
            ans+=sum+mcnt;
        }
        if(pcnt!=0)
        {
            int sum=accumulate(travel.begin(),travel.begin()+p,0);
            ans+=sum+pcnt;
        }
        return ans;
    }
};