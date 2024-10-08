class Solution {
    public boolean check(Stack<Integer> st,String s,char ch){
        if(s.charAt(st.peek()) == '(' && ch == ')')
            return true;
        return false;
    }
    
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> st = new Stack<>();
        
        int i = 0;
        while(i<s.length()){
            while(i<s.length() && !st.isEmpty() && check(st,s,s.charAt(i))){
                st.pop();
                i++;
            }
            if(i<s.length() && (s.charAt(i) == '(' || s.charAt(i) == ')')){
                st.push(i);
                i++;
            }
            else{
                i++;
            }
        }
        
        
        HashSet<Integer> hs = new HashSet<>();
        while(!st.isEmpty()){
            hs.add(st.peek());
            st.pop();
        }
        
        StringBuilder ans = new StringBuilder();
        for(i=0;i<s.length();i++){
            if((s.charAt(i) == '(' || s.charAt(i) == ')') && !hs.contains(i)){
                ans.append(s.charAt(i));
            }
            else if(s.charAt(i) >= 97 && s.charAt(i)<=122){
                ans.append(s.charAt(i));
            }
        }
        
        return ans.toString();
    }
}