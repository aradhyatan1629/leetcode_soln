class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        unordered_map<int,int> m;
        vector<int> ans;
        
        if(changed.size()%2!=0 or count(changed.begin(),changed.end(),0)%2!=0)
            return {};
        
        for(int i=0;i<changed.size();i++)
            m[changed[i]]++;
        
        for(int i=0;i<changed.size();i++)
        {
            if(m[changed[i]]==0)
                continue;
            else if(m[changed[i]] <= m[changed[i]*2])
                ans.push_back(changed[i]);
                m[changed[i]]--;m[changed[i]*2]--;
        }
        if(ans.size()==changed.size()/2)
            return ans;
        return {};
    }
};
