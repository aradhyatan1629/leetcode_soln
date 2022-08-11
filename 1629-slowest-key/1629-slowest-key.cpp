class Solution {
public:
    char slowestKey(vector<int>& r, string key) {
        int mx = r[0];
        char prev = key[0];
        int index;
        for(int i=1;i<key.size();i++)
        {
            int press = r[i]-r[i-1];
            if(press>mx)
            {
                mx = press;
                prev=key[i];
            }
            if(press==mx and key[i]>=prev)
            {
                mx=press;
                prev=key[i];
            }
        }
        return prev;
    }
};