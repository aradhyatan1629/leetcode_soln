class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        if(words.size()==1)
        {
            return true;
        }
        for(int i=0;i<order.size();i++)
        {
            m[order[i]] = i;
        }
        for(int i=1;i<words.size();i++)
        {
            int k=0;
            int flag=1;
            for(int j=0;j<words[i].size();j++)
            {
                if(k<words[i-1].size() and m[words[i][j]] < m[words[i-1][k]])
                {
                    return false;
                }
                else if(words[i-1][k]==words[i][j])
                {
                    flag=-1;
                    k++;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag==-1 and words[i-1].size()>words[i].size())
            {
                return false;
            }
        }
        return true;
    }
};