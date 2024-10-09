class Solution {
    public int minAddToMakeValid(String s) {
        int open = 0;
        int closed = 0;
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '(')
                open++;
            else if(s.charAt(i) == ')' && open>0)
                open--;
            else if(s.charAt(i) == ')')
                closed++;
        }
        return open+closed;
    }
}