class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        //O(n) O(n)
        vector<int> v;
        vector<int> ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==c)
            {
                v.push_back(i);
            }
        }
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(j==0)
            {
                ans.push_back(v[j]-i);
            }
            else if(j>=v.size())
            {
                ans.push_back(i-v[j-1]);
            }
            else
            {
                ans.push_back(min(v[j]-i,i-v[j-1]));
            }
            if(s[i]==c)
            {
                j++;
            }
        }
        return ans;
    }
};



// [3,5,6,11]