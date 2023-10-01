class Solution {
public:
    
    vector<int> NSL(vector<int> &heights)
    {
        stack<pair<int,int>> st;     //{height,index}
        vector<int> v;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty())
            {
                v.push_back(-1);
            }
            else if(!st.empty() and st.top().first<heights[i])
            {
                v.push_back(st.top().second);
            }
            else if(!st.empty() and st.top().first>=heights[i])
            {
                while(!st.empty() and st.top().first>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        return v;
    }
    
    vector<int> NSR(vector<int> &heights)
    {
        stack<pair<int,int>> st;         //{height,index}
        vector<int> v;
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                v.push_back(heights.size());
            }
            else if(!st.empty() and st.top().first<heights[i])
            {
                v.push_back(st.top().second);
            }
            else if(!st.empty() and st.top().first>=heights[i])
            {
                while(!st.empty() and st.top().first>=heights[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(heights.size());
                }
                else
                {
                    v.push_back(st.top().second);
                }
            }
            st.push({heights[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = NSL(heights); 
        vector<int> nsr = NSR(heights);
        vector<int> widths;
        
        for(int i=0;i<nsl.size();i++)
        {
            widths.push_back(nsr[i]-nsl[i]-1);
        }
        int mx=0;
        for(int i=0;i<heights.size();i++)
        {
            mx=max(mx,widths[i]*heights[i]);
        }
        return mx;
    }
};