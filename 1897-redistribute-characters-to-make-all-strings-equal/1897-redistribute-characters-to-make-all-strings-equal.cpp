class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size()==1)
        {
            return true;
        }
        unordered_map<char,int> m;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                m[words[i][j]]++;
            }
        }
        int n = words.size();
         for(auto x:m)
         {
             if(x.second%n!=0)
             {
                 return false;
             }
         }
        return true;
    }
};