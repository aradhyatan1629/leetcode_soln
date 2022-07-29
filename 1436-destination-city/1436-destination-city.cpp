class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,string> m;
        for(int i=0;i<paths.size();i++)
        {
            m[paths[i][0]] = paths[i][1];
        }
        vector<string> v;
        for(auto x:m)
        {
            v.push_back(x.first);
        }
        for(int i=0;i<paths.size();i++)
        {
            string t = paths[i][1];
            if(find(v.begin(),v.end(),t)==v.end())
            {
                return t;
                break;
            }
        }
        return "";
    }
};