class Solution {
public:
    bool check(stack<char> &st,char ch){
        if(st.top() == '[' && ch == ']')
            return true;
        return false;
    }
    
    int minSwaps(string s) {
        if(s.size() == 0)
            return 0;
        
        int i = 0;
        stack<char> st;
        while(i<s.size()){
            while(!st.empty() && check(st,s[i])){
                st.pop();
                i++;
            }
            st.push(s[i]);
            i++;
        }
        int open = st.size()/2;
        return (open+1)/2;
        
    }
};


/*
]] [[

]]] [[[


pattern - (no. of opening brackets after removing balanced strings + 1)/2;


*/
