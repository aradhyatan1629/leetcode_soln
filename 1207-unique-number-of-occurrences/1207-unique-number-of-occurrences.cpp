class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> o;
        unordered_map<int,bool> m;
        for(auto x:arr)
        {
            o[x]++;
        }
        for(auto x:o)
        {
            if(m[x.second]==true)
            {
                return false;
            }
            else
            {
                m[x.second]=true;
            }
        }
        return true;
    }
};