class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        vector<string> ans;
        string word;
        int sz=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                v.push_back(word);
                int x=word.size();
                sz=max(sz,x);
                word.clear();
            }
            else
            {
                word+=s[i];
            }
        }
        v.push_back(word);
        int x=word.size();
        sz=max(sz,x);
        word.clear();
        int m=v.size();
        int n=sz;
        int r=-1;
        // cout<<v[2][2]<<endl;
        // return {};
        for(int j=0;j<n;++j)
        {
            for(int i=0;i<m;++i)
            {
                if(v[i][j]>=65 && v[i][j]<=91)
                {
                    word+=v[i][j];
                }
                else
                {
                    word+=' ';
                }
            }
            for(auto it=word.end()-1;it>=word.begin();it--)
            {
                if(*it>=65 && *it<=91)
                {
                    break;
                }
                else if(*it==' ')
                {
                    word.erase(it);
                }
            }
            ans.push_back(word);
            word.clear();
        }
        return ans;
    }
};