class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,n=fruits.size();
        unordered_map<int,int> m;
        int mx=0,cnt=0;
        while(j<n and i<n)
        {
            m[fruits[j]]++;;
            if(m.size()<=2)
            {
                cnt++;
                j++;
            }
            else
            {
                mx=max(mx,cnt);
                m[fruits[i]]--;
                if(m[fruits[i]]==0)
                {
                    m.erase(fruits[i]);
                }
                i++;
                j++;
            }
        }
        mx=max(cnt,mx);
        return mx;
    }
};