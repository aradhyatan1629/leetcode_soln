class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& rest, int veganfriendly, int maxprice, int maxdistance) {
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i=0;i<rest.size();i++)
        {
            if(veganfriendly==1)
            {
                if(rest[i][2]==1 && rest[i][3]<=maxprice && rest[i][4]<=maxdistance)
                {
                    v.push_back({rest[i][1],rest[i][0]});
                }
            }
            else
            {
                if(rest[i][3]<=maxprice && rest[i][4]<=maxdistance)
                {
                    v.push_back({rest[i][1],rest[i][0]});
                }
            }
        }
        sort(v.begin(),v.end());
        /*for(auto x:v)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }*/
        for(int i=v.size()-1;i>=0;i--)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};