class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int cnt=0;
        while(i>=0 and s[i]==' ')
            i--;
        while(i>=0 and s[i]!=' ')
            cnt++,i--;
        return cnt;
    }
};