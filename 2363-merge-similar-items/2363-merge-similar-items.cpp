class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> m1;
        vector<vector<int>> ans;
        for(int i=0;i<items1.size();i++)
        {
            m1[items1[i][0]] = items1[i][1];
        }
        for(int i=0;i<items2.size();i++)
        {
            m1[items2[i][0]] += items2[i][1];
        }
        for(auto x:m1)
        {
            vector<int> v;
            v.push_back(x.first);
            v.push_back(x.second);
            ans.push_back(v);
        }
        return ans;
    }
};