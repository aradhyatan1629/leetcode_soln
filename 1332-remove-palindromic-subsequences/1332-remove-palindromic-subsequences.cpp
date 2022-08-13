class Solution {
public:
    int removePalindromeSub(string s){
        string r = s;
        reverse(r.begin(),r.end());
        if(r==s)
        {
            return 1;
        }
        return 2;
    }
};