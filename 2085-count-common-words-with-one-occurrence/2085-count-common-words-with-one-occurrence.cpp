class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int i=0,cnt=0;
        unordered_map<string,int> m1;
        unordered_map<string,int> m2;
        for(i=0;i<words1.size();i++)
        {
            m1[words1[i]]++;
        }
        for(i=0;i<words2.size();i++)
        {
            m2[words2[i]]++;
        }
        for(i=0;i<words1.size();i++)
        {
            if(m1[words1[i]]==1 and m2[words1[i]]==1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};