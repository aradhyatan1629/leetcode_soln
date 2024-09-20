class Solution {
public:
    bool solve(string &s,int i,int j){
        bool flag = true;
        i++;
        while(i<j){
            if(s[i] != s[j]){
                flag = false;
                break;
            }
            i++,j--;
        }
        return flag;
    }
    
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        bool flag = true;
        
        while(i<j){
            if(s[i]!=s[j] && !flag)
                return false;
            else if(s[i]!=s[j] && flag){
                flag = false;
                if(s[i+1] == s[j] && s[i] == s[j-1]){
                    if(solve(s,i,j))i++;
                    else j--;
                }
                else if(s[i+1] == s[j])i++;
                else if(s[i] == s[j-1])j--;
                else i++;
            }
            else
                i++,j--;
        }
        return true;
    }
};




/*

efgh
efeh

abc


*/





