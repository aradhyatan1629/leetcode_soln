class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int cnt=0;
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(words[i]!=words[j] and words[j].find(words[i])!=-1)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};