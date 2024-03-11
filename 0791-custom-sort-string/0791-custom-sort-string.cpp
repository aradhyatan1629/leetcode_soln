class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(auto x:s)
            m[x]++;
        int i=0;
        string ans;
        while(i<order.size())
        {
            while(m[order[i]]>0)
            {
                ans+=order[i];
                m[order[i]]--;
            }
            i++;
        }
        for(auto x:m)
        {
            if(x.second!=0)
            {
                while(x.second>0)
                {
                    ans+=x.first;
                    x.second--;
                }
            }
        }
        return ans;
    }
};