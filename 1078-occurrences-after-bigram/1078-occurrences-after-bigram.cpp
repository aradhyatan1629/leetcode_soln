class Solution {
public:
    bool check(string a, string b)
    {
        return a == b;
    }
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> v;
        vector<string> ans;
        string word;
        for(int i=0;i<text.size();i++)
        {
            
            if(text[i]==' ')
            {
                v.push_back(word);
                word.clear();
            }
            else 
            {
                word += text[i];
            }
        }
        v.push_back(word);
        word.clear();
        for(int i = 0; i<v.size()-2; i++)
        {
            if(check(v[i], first) && check(v[i+1], second))
                ans.push_back(v[i+2]);
        }
        return ans;
    }
};