class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int score=0;
        for(int i=0;i<directions.size();i++)
        {
            if(st.empty())
            {
                st.push(directions[i]);
            }
            else
            {
                if(st.top()=='R' and directions[i]=='L')
                {
                    score+=2;
                    st.pop();
                    while(!st.empty() and st.top()=='R')
                    {
                        st.pop();
                        score+=1;
                    }
                    st.push('S');
                }
                else if(st.top()=='R' and directions[i]=='S')
                {
                    score+=1;
                    st.pop();
                    while(!st.empty() and st.top()=='R')
                    {
                        score+=1;
                        st.pop();
                    }
                    st.push('S');
                }
                else if(st.top()=='S' and directions[i]=='L')
                {
                    score+=1;
                }
                else
                {
                    st.push(directions[i]);
                }
            }
        }
        return score;
    }
};
