class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                m[words[i][j]]++;
            }
        }
        
        for(auto x:m)
        {
            if(x.second%words.size() != 0)
                return false;
        }
        return true;
    }
};