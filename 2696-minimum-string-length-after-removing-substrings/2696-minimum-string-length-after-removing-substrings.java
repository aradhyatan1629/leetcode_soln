class Solution {
    public boolean check(Stack<Character> st,char ch){
        if(st.peek() == 'A' && ch == 'B')
            return true;
        if(st.peek() == 'C' && ch == 'D')
            return true;
        return false;
    }
    
    public int minLength(String s) {
        Stack<Character> st = new Stack<>();
        
        int i=0;
        while(i<s.length()){
            while(i<s.length() && !st.isEmpty() && check(st,s.charAt(i))){
                st.pop();
                i++;
            }
            if(i == s.length())
                break;
            st.push(s.charAt(i));
            i++;
        }
        return st.size();
    }
}