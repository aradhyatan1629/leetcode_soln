class Solution {
public:
    char slowestKey(vector<int>& r, string key) {
        map<char,int> m;
        m[key[0]] = r[0];
        int mx = INT_MIN;
        char ans;
        for(int i=1;i<key.size();i++)
        {
            int press = r[i] - r[i-1];
            if(press>=m[key[i]])
            {
                m[key[i]] = press;
            }
        }
        for(auto x:m)
        {
            if(x.second>=mx)
            {
                mx=x.second;
                ans=x.first;
            }
        }
        return ans;
    }
};