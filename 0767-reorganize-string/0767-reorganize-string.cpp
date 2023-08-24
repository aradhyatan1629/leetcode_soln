class Solution {
public:
    string reorganizeString(string s) {
        vector<int> v(26,0);
        priority_queue<pair<int,char>> pq;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'a']++;
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>0)
            {
                pq.push({v[i],(char)('a'+i)});
            }
        }
        auto block = pq.top();
        pq.pop();
        ans+=block.second;
        block.first--;
        while(pq.size()>0)
        {
            auto top = pq.top();
            pq.pop();
            ans+=top.second;
            top.first--;
            if(block.first>0)
            {
                pq.push(block);
            }
            block = top;
        }
        if(block.first>0)
        {
            return "";
        }
        return ans;
    }
};