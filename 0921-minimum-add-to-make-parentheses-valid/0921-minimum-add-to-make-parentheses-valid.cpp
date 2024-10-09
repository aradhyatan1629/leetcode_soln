class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 0)
            return 0;
        
        int open = 0;
        int closed = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')
                open++;
            else if(s[i] == ')' && open>0)
                open--;
            else if(s[i] == ')')
                closed++;
        }
        return open+closed;
    }
};