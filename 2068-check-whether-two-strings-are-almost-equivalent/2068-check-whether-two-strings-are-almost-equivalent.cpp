class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        int i=0;
        for(i=0;i<word1.size();i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        for(auto x:word1)
        {
            if(abs(m1[x]-m2[x])>3)
            {
                return false;
            }
        }
        for(auto x:word2)
        {
            if(abs(m1[x]-m2[x])>3)
            {
                return false;
            }
        }
        return true;
    }
};