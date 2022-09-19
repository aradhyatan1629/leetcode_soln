class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> m;
        vector<string> v;
        for(int i=0;i<messages.size();i++)
        {
            int cnt=0;
            for(int j=0;j<messages[i].size();j++)
            {
                if(messages[i][j]==' ')
                {
                    cnt++;
                }
            }
            m[senders[i]] += cnt+1;
        }
        int mx;
        for(auto x:m)
        {
            mx=max(mx,x.second);
        }
        for(auto x:m)
        {
            if(x.second==mx)
            {
                v.push_back(x.first);
            }
        }
        sort(v.begin(),v.end());
        return v[v.size()-1];
    }
};