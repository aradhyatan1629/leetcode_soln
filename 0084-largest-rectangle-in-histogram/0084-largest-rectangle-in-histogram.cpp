class Solution {
public:
    
    vector<int> nearestSmallertoLeft(vector<int> &h)
    {
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i=0;i<h.size();i++)
        {
            if(st.size()==0)
            {
                ans.push_back(-1);
            }
            else if(st.size()>0 and st.top().first<h[i])
            {
                ans.push_back(st.top().second);
            }
            else if(st.size()>0 and st.top().first>=h[i])
            {
                while(st.size()>0 and st.top().first>=h[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(st.top().second);
                }
            }
            st.push({h[i],i});
        }
        return ans;
    }
    
    vector<int> nearestSmallertoRight(vector<int> &h)
    {
        stack<pair<int,int>> st;
        vector<int> ans;
        for(int i=h.size()-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                ans.push_back(h.size());
            }
            else if(st.size()>0 and st.top().first<h[i])
            {
                ans.push_back(st.top().second);
            }
            else if(st.size()>0 and st.top().first>=h[i])
            {
                while(st.size()>0 and st.top().first>=h[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    ans.push_back(h.size());
                }
                else
                {
                    ans.push_back(st.top().second);
                }
            }
            st.push({h[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = nearestSmallertoLeft(heights);
        vector<int> nsr = nearestSmallertoRight(heights);
        vector<int> widths;
        int mx=0;
        for(int i=0;i<nsl.size();i++)
        {
            widths.push_back(nsr[i]-nsl[i]-1);
        }
        for(int i=0;i<heights.size();i++)
        {
            mx = max(mx,heights[i]*widths[i]);
        }
        return mx;
        
    }
};