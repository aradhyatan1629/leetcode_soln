class Solution {
    public void solve(Stack<Character> st,int lastResult,int op,int t,int f){
        if(op == '&'){
            if(f == 0)st.push('t');
            else st.push('f');
        }
        else if(op == '|'){
            if(t != 0)st.push('t');
            else st.push('f');
        }
        else if(op == '!'){
            if(lastResult == 't')st.push('f');
            else st.push('t');
        }
    }
    
    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();
        int n = expression.length();
        
        for(int i=0;i<n;i++){
            int t = 0;int f = 0;
            char lastResult = '\0';
            if(expression.charAt(i) == ')'){
                while(st.peek() != '('){
                    if(st.peek() == 't')t++;
                    else if(st.peek() == 'f')f++;
                    lastResult = st.peek();
                    st.pop();
                }
                st.pop();
                char op = st.peek();st.pop();
                solve(st,lastResult,op,t,f);
            }
            else if(expression.charAt(i) != ','){
                st.push(expression.charAt(i));
            }
        }
        if(st.peek() == 't')
            return true;
        return false;
    }
}