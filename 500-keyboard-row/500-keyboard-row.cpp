class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> first = {'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> second = {'a','s','d','f','g','h','j','k','l'};
        unordered_set<char>  third= {'z','x','c','v','b','n','m'};
        vector<string> ans;
        
        for(int i=0;i<words.size();i++)
        {
            bool f=true,s=true,t=true;
            for(int j=0;j<words[i].size();j++)
            {
                if(first.find(words[i][j])!=first.end())
                {
                    f=false;
                }
                if(second.find(words[i][j])!=second.end())
                {
                    s=false;
                }
                if(third.find(words[i][j])!=third.end())
                {
                    t=false;
                }
            }
            if(f==false)
            {
                if(s==true and t==true)
                {
                    ans.push_back(words[i]);
                }
            }
            if(s==false)
            {
                if(f==true and t==true)
                {
                    ans.push_back(words[i]);
                }
            }
            if(t==false)
            {
                if(f==true and s==true)
                {
                    ans.push_back(words[i]);
                }
            }
        }
        return ans;
    }
};