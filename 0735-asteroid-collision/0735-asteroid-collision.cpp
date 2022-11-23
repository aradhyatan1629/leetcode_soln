    class Solution {
    public:
        bool check(int st_top,int ast)
        {
            if(st_top>0 and ast<0)
            {
                return true;
            }
            return false;
        }
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> st;
            vector<int> ans;
            for(int i=0;i<asteroids.size();i++)
            {
                if(st.empty())
                {
                    st.push(asteroids[i]);
                }
                else if(check(st.top(),asteroids[i]))
                {
                    if(abs(st.top())==abs(asteroids[i]))
                    {
                        st.pop();
                    }
                    else if(abs(st.top())<abs(asteroids[i]))
                    {
                        int flag=-1;
                        while(abs(st.top())<abs(asteroids[i]) and check(st.top(),asteroids[i]))
                        {
                            st.pop();
                            flag=1;
                            if(st.empty())
                            {
                                break;
                            }
                        }
                        if(st.empty())
                        {
                            st.push(asteroids[i]);
                        }
                        else if(abs(st.top())==abs(asteroids[i]) and check(st.top(),asteroids[i]))
                        {
                            st.pop();
                            if(st.empty())
                            {
                                continue;
                            }
                        }
                        else if(abs(st.top())==abs(asteroids[i]) and check(st.top(),asteroids[i])==false)
                        {
                            st.push(asteroids[i]);
                        }
                        else if(st.top()>0 and asteroids[i]>0 or st.top()<0 and asteroids[i]<0)
                        {
                            st.push(asteroids[i]);
                        }
                        else if(flag==1)
                        {
                            continue;
                        }
                        else
                        {
                            st.push(asteroids[i]);
                        }
                    }
                }
                else
                {
                    st.push(asteroids[i]);
                }
            }
            if(st.empty())
            {
                return {};
            }
            while(!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };