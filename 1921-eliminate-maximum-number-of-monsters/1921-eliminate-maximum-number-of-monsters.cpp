class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        if(dist.size()==1){return 1;}
        vector<double> v;
        for(int i=0;i<dist.size();i++)
        {
            double time = (double)dist[i] / (double)speed[i];
            v.push_back(time);
        }
        sort(v.begin(),v.end());
                
        int t=0;
        int cnt=0;
        for(int i=0;i<v.size();i++)
        {
            if(t>=v[i])
            {
                break;
            }
            else
            {
                cnt++;
                t++;
            }
        }
        return cnt;
    }
};



/*

0.6,0.6,2



*/