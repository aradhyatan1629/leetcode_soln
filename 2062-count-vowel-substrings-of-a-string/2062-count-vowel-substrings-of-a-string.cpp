class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> s;
        int ans=0;
        int n = word.size();
        for(int i=0;i<n;++i)
        {
            for(int j=i;j<n;++j)
            {
                if(word[j]=='a'||word[j]=='e'||word[j]=='i'||word[j]=='o'||word[j]=='u')
                {
                    s.insert(word[j]);
                }
                else
                {
                    break;
                }
                if(s.size()==5)
                {
                    ans++;
                }
            }
            s.clear();
        }
        return ans;
    }
};