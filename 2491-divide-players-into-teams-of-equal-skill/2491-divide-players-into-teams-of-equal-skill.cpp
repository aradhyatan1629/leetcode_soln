class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        sort(skill.begin(),skill.end());
        int n=skill.size(),i=0,j=n-1,sum=0;
        sum=skill[0]+skill[n-1];
        while(i<j)
        {
            int prod=skill[i]*skill[j];
            ans+=prod;
            if(skill[i]+skill[j]!=sum)
            {
                return -1;
            }
            i++;
            j--;
        }
        return ans;
    }
};