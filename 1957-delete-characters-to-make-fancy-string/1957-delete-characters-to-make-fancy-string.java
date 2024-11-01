class Solution {
    public String makeFancyString(String s) {
        Stack<Character> st = new Stack<>();
        
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(st.size() >= 2 && st.peek() == ch){
                char top1 = st.peek();st.pop();
                char top2 = st.peek();st.pop();
                boolean flag = false;
                if(top1 != ch || top2 != ch){
                    flag = true;
                }
                st.push(top2);
                st.push(top1);
                if(flag)st.push(ch);
            }
            else{
                st.push(ch);
            }
        }
        
        StringBuilder ans = new StringBuilder();
        while(!st.isEmpty()){
            ans.append(st.peek());
            st.pop();
        }
        return ans.reverse().toString();
        
    }
}

