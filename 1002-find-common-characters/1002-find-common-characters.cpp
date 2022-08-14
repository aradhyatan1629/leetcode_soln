class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> m;
        vector<string> ans;
        for(auto x:words[0])
        {
            m[x]++;
        }
        for(int i=1;i<words.size();i++)
        {
            unordered_map<char,int> temp;
            for(auto y:words[i])
            {
                temp[y]++;
            }
            for(int i=0;i<26;i++)
            {
                char ch = 'a'+i;
                if(temp.find(ch)!=temp.end() && m.find(ch)!=m.end())
                {
                    m[ch] = min(m[ch],temp[ch]);
                }
                else if(m.find(ch)!=m.end())
                {
                    m.erase(ch);
                }
            }
        }
        for(auto x:m)
        {
            string s="";
            s+=x.first;
            while(x.second--)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};