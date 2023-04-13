class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> st;
        while(i<pushed.size())
        {
            if(st.empty())
            {
                st.push(pushed[i]);
            }
            else if(st.top()==popped[j])
            {
                while(!st.empty() and st.top()==popped[j] and j<popped.size())
                {
                    st.pop();
                    j++;
                }
            }
            st.push(pushed[i]);
            i++;
        }
        while(j<popped.size())
        {
            if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};





/*
2 1 0
1 2 0
*/




 






