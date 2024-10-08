class Solution {
    public boolean check(Stack<Character> st,char ch){
        if(st.peek() == '[' && ch == ']')
            return true;
        return false;
    }
    
    int minSwaps(String s) {
        Stack<Character> st = new Stack<>();
        int i = 0;
        while(i<s.length()){
            while(!st.isEmpty() && i<s.length() && check(st,s.charAt(i))){
                st.pop();
                i++;
            }
            if(i<s.length()){
                st.push(s.charAt(i));
                i++;
            }
        }
        int open = st.size()/2;
        return (open+1)/2;
    }
};