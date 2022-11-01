class Solution {
public:
    string arrangeWords(string text) {
        vector<pair<int,int>> v;
        vector<string> v1;
        string word,ans;
        int ind=0;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]==' ')
            {
                int sz=word.size();
                v.push_back({sz,ind++});
                v1.push_back(word);
                word.clear();
            }
            else
            {
                word+=text[i];
            }
        }
        int sz=word.size();
        v.push_back({sz,ind++});
        v1.push_back(word);
        word.clear();
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            ans+=v1[v[i].second];
            ans+=" ";
        }
        ans.erase(ans.end()-1);
        transform(ans.begin(),ans.end(),ans.begin(),::tolower);
        if(ans[0]>=97 and ans[0]<=122)
        {
            ans[0]=ans[0]-32;
        }
        return ans;
    }
};

