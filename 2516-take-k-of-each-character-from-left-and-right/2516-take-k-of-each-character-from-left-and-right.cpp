class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int> m;
        int n = s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
        }
        
        if(m['a'] < k || m['b'] < k || m['c'] < k)
            return -1;
    
        int i=0,j=0;
        int mxLen = 0;  // maximum window length that we will not delete
        while(j<n){
            m[s[j]]--;
            if(m[s[j]] >= k){
                mxLen = max(mxLen,j-i+1);
                j++;
            }
            else{
                while(m[s[j]] < k){
                    m[s[i]]++;
                    i++;
                }
                j++;
            }
        }
        return n-mxLen;
    }
};