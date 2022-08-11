class Solution {
public:
    bool detectCapitalUse(string word) {
        unordered_map<char,int> cap;
        unordered_map<char,int> low;
        for(auto x:word)
        {
            if(x>=65 and x<=90)
            {
                cap[x]++;
            }
            else
            {
                low[x]++;
            }
        }
        if(cap.size()!=0 and low.size()==0)
        {
            return true;
        }
        if(low.size()!=0 and cap.size()==0)
        {
            return true;
        }
        if(cap.size()==1 and cap[word[0]]==1)
        {
           return true;
        }
        return false;
    }
};