class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m1,m2;
        for(auto x:arr)
        {
            m1[x]++;
        }
        for(auto x:m1)
        {
            if(m2[m1[x.first]]==1)
                return false;
            m2[m1[x.first]]=1;
        }
        return true;
    }
};