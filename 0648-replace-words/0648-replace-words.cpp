class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> m;
        for(int i=0;i<dictionary.size();i++)
        {
            m[dictionary[i]]=1;
        }
        string word;
        string ans;
        for(int i=0;i<sentence.size();i++)
        {
            if(sentence[i]==' ')
            {
                ans += word;
                ans += " ";
                word = "";
            }
            else
            {
                word += sentence[i];
                if(m.find(word) != m.end())
                {
                    ans += word;
                    ans += " ";
                    word = "";
                    while(i<sentence.size() && sentence[i]!=' ')
                        i++;
                }
            }
        }
        if(word != "")
            ans+=word;
          if(ans[ans.size()-1] == ' ')
            ans.erase(ans.end()-1);
        
        return ans;
    }
};