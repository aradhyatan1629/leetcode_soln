class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        if(n > m)
            return false;
        
        int i=0;
        int j=0;
        
        while(i<m && j<n){
            if(str1[i] == str2[j]){
                i++;
                j++;
            }
            else{
                if('a' + (str1[i] - 'a' + 1)%26 == str2[j]){
                    i++;
                    j++;
                }
                else{
                    i++;
                }
            }
        }
        if(j == n)
            return true;
        return false;
        
    }
};