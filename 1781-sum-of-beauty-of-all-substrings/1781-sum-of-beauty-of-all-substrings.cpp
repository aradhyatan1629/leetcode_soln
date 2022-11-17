class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int k=3;k<=s.size();k++)
        {
            int i=0,j=0,n=s.size();
            unordered_map<char,int> m;
            while(j<n)
            {
                m[s[j]]++;
                if(j-i+1<k)
                {
                    j++;
                }
                else if(j-i+1==k)
                {
                    // for(auto x:m)
                    // {
                    //     cout<<x.first<<" "<<x.second<<" ";
                    // }
                    // cout<<endl;
                    int mx = INT_MIN;
                    int mn = INT_MAX;
                    for(auto x:m)
                    {
                        mx = max(mx,x.second);
                        mn = min(mn,x.second);
                    }
                    sum+=(mx-mn);
                    if(m[s[i]]>0)
                    {
                        m[s[i]]--;
                    }
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                    j++;
                }
            }
        }
        return sum;
    }
};