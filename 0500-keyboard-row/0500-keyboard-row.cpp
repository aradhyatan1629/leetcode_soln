class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> s1 = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> s2 = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> s3 = {'z','x','c','v','b','n','m'};
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            bool flag1=false;
            bool flag2=false;
            bool flag3=false;
            for(int j=0;j<words[i].size();j++)
            {
                if(s1.find(words[i][j])!=s1.end())
                {
                    flag1=true;
                }
                if(s2.find(words[i][j])!=s2.end())
                {
                    flag2=true;
                }
                if(s3.find(words[i][j])!=s3.end())
                {
                    flag3=true;
                }
            }
            if(flag1==true and flag2==false and flag3==false)
            {
                ans.push_back(words[i]);
            }
            if(flag2==true and flag1==false and flag3==false)
            {
                ans.push_back(words[i]);
            }
            if(flag3==true and flag1==false and flag2==false)
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};