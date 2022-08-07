class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        for(int i=0;i<n;i+=k)
        {
            string word;
            for(int j=i;j<i+k;++j)
            {
                if(j>=n)
                {
                    break;
                }
                word+=s[j];
            }
            if(word.size()<k)
            {
                while(word.size()!=k)
                {
                    word+=fill;
                }
            }
            ans.push_back(word);
        }
        return ans;
    }
};