class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> s1;
        int cnt=1;
        if(s.size()==1)
        {
            return 1;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s1.size()==0)
            {
                s1.insert(s[i]);
            }
            else 
            {
                if(s1.find(s[i])==s1.end())
                {
                    s1.insert(s[i]);
                }
                else
                {
                    s1.clear();
                    s1.insert(s[i]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};