class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int> answer;
        int i=0;
        while(i<n)
        {
            int j=i-1;
            int k=i+1;
            int ans=INT_MAX;
            if(s[i]==c)
            {
                answer.push_back(0);
                i++;
                continue;
            }
            while(j>=0 and s[j]!=c)
            {
                j--;
            }
            while(k<n and s[k]!=c)
            {
                k++;
            }
            if(j==-1)
            {
                answer.push_back(abs(i-k));
            }
            else if(k==n)
            {
                answer.push_back(abs(i-j));
            }
            else
            {
                ans=min(abs(i-j),abs(i-k));
                answer.push_back(ans);
            }
            i++;
        }
        return answer;
    }
};