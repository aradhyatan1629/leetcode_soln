class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size()==0)
        {
            return 0;
        }
        int i=0,j=0,n=s.size();
        int mxCnt = 0,ans=0;
        unordered_map<int,int> m;
        
        while(j<n)
        {
            m[s[j]]++;
            mxCnt = max(mxCnt,m[s[j]]);
            
            while((j-i+1) - mxCnt > k)
            {
                m[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};


/*
Intuition - how will you find the length of the longest substring containing the same letter if you forget about k
 X = (length of the string - freq of maximum occuring character in the string)
 This will give us the number of characters which are "NOT" the maximum freq character, we can replace all of them 
*/