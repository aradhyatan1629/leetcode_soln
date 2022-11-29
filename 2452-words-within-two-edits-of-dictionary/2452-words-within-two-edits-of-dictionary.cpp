class Solution {
public:
    bool check(string s1,string s2)
    {
        int diff=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                diff++;
            }
        }
        if(diff<=2)
        {
            return true;
        }
        return false;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(int i=0;i<queries.size();i++)
        {
            for(int j=0;j<dictionary.size();j++)
            {
                if(check(queries[i],dictionary[j]))
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};