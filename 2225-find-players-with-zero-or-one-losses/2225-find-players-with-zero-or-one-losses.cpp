class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> w,l;
        for(int i=0;i<matches.size();i++)
        {
            if(w[matches[i][0]]!=-1)
            {
                w[matches[i][0]]++;
                w[matches[i][1]]=-1;
                l[matches[i][1]]++;
            }
            else
            {
                // l[matches[i][0]]++;
                l[matches[i][1]]++;
                w[matches[i][1]]=-1;
            }
        }
        
        // for(auto x:w)cout<<x.first<<" "<<x.second<<endl;
        // cout<<endl;
        // for(auto x:l)cout<<x.first<<" "<<x.second<<endl;
        
        vector<vector<int>> ans;
        vector<int> v;
        for(auto x:w)
            if(w[x.first]!=-1)
                v.push_back(x.first);
        ans.push_back(v);
        v.clear();
        
        for(auto x:l)
            if(l[x.first]==1)
                v.push_back(x.first);
        ans.push_back(v);
        return ans;
        
    }
};


/*












*/