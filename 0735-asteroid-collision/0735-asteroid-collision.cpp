class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty() or asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while(!st.empty() and (st.top()>0 and st.top()<abs(asteroids[i])))
                {
                    st.pop();
                }
                if(!st.empty() and (st.top()) == abs(asteroids[i]))
                {
                    st.pop();
                }
                else
                {
                    if(st.empty() or st.top()<0)
                    {
                        st.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};