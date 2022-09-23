class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int,map<string,int>> m;
        vector<vector<string>> ans;
        vector<string> v;
        set<string> s;
        for(int i=0;i<orders.size();i++)
        {
            s.insert(orders[i][2]);
            m[stoi(orders[i][1])][orders[i][2]]++;
        }
        v.push_back("Table");
        for(auto x:s)
        {
            v.push_back(x);
        }
        ans.push_back(v);
        for(auto x:m)
        {
            vector<string> temp;
            temp.push_back(to_string(x.first));
            for(auto y:s)
            {
                if(x.second.find(y)!=x.second.end())
                {
                    temp.push_back(to_string(x.second[y]));
                }
                else
                {
                    temp.push_back("0");
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};