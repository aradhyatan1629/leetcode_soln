class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int cnt[26]={};
        for(auto x:word1)
        {
            cnt[x-'a']++;
        }
         for(auto x:word2)
        {
            cnt[x-'a']--;
        }
        for(int i=0;i<26;i++)
        {
            if(abs(cnt[i])>3)
            {
                return false;
            }
        }
        return true;
    }
};