class Solution {
public:
    void solve(char op,stack<char> &st,char lastResult,int t,int f){
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
    
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();
        
        for(int i=0;i<n;i++){
            if(expression[i] == ')'){
                int t=0,f=0;
                char lastResult;
                while(st.top() != '('){
                    if(st.top() == 't')t++;
                    else if(st.top() == 'f')f++;
                    lastResult = st.top();
                    st.pop();
                }
                st.pop();char op = st.top();
                st.pop();
                solve(op,st,lastResult,t,f);
            }
            else if(expression[i] != ','){
                st.push(expression[i]);
            }
        }
        if(st.top() == 't')
            return true;
        return false;
    }
};