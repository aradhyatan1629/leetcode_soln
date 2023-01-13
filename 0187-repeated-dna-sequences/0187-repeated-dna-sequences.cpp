class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        int i=0,j=0,n=s.size();
        string temp;
        vector<string> ans;
        while(j<n)
        {
            temp+=s[j];
            if(j-i+1<10)
            {
                j++;
            }
            else if(j-i+1==10)
            {
                m[temp]++;
                temp.erase(temp.begin());
                i++;
                j++;
            }
        }
        for(auto x:m)
        {
            if(x.second>1)
            {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};