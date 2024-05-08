class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp(score.begin(),score.end());
        sort(temp.begin(),temp.end(),greater<int>());
        unordered_map<int,string> m;
        for(int i=0;i<temp.size();i++)
        {
            if(i>2)
                m[temp[i]] = to_string(i+1);
            else if(i==0)
                m[temp[i]] = "Gold Medal";
            else if(i==1)
                m[temp[i]] = "Silver Medal";
            else if(i==2)
                m[temp[i]] = "Bronze Medal";
        }
        vector<string> ans;
        for(int i=0;i<score.size();i++)
        {
            ans.push_back(m[score[i]]);
        }
        return ans;
    }
};