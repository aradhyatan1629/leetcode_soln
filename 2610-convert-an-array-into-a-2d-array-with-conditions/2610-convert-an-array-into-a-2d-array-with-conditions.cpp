class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m,m1;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
     
        vector<vector<int>> ans;
        while(m1.size()!=m.size())
        {
            vector<int> v;
            for(auto x:m)
            {
                if(m[x.first]>0)
                    v.push_back(x.first);
                else if(m[x.first]==0)
                    m1[x.first]=1;
                m[x.first]--;                
            }
            if(v.size()>0)
                ans.push_back(v);
        }
        return ans;
    }
};


