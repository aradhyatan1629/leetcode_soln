class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        unordered_map<int,int> m;
        int i=0,j=0,n=fruits.size();
        
        while(j<n)
        {
            m[fruits[j]]++;
            if(m.size()<=2)
            {
                j++;
            }
            else
            {
                ans = max(ans,j-i);
                while(m.size()>2)
                {
                    m[fruits[i]]--;
                    if(m[fruits[i]]==0)m.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        ans = max(ans,j-i);
        return ans;
    }
};


/*

1,2,1,3,2,2,3,5,1,1

*/