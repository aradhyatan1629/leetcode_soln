class Solution {
public:
    int isPrefixOfWord(string sent, string search) {
        vector<string> v;
        int n=search.size();
        string word;
        int i=0;
        for(i=0;i<sent.size();i++)
        {
            if(sent[i]==' ')
            {
                v.push_back(word);
                word.clear();
            }
            else
            {
                word+=sent[i];
            }
            if(i==sent.size()-1)
            {
                v.push_back(word);
                word.clear();
            }
        }
        for(i=0;i<v.size();i++)
        {
            if(v[i].substr(0,n) == search)
            {
                return i+1;
                break;
            }
        }
        return -1;
    }
};