class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,pair<int,int>> w;
        unordered_map<int,pair<int,int>> l;
        vector<vector<int>> ans;
        for(int i=0;i<matches.size();i++)
        {
            w[matches[i][0]].first++;
            w[matches[i][1]].first++;
            w[matches[i][1]].second++;
        }
        vector<int> v1;
        vector<int> v2;
        for(auto x:w)
        {
            if(x.second.second==0)
            {
                v1.push_back(x.first);
            }
            else if(x.second.second==1)
            {
                v2.push_back(x.first);
            }
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
// pair <total matches,matches lost>