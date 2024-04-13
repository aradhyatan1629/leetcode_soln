class Solution {
public:
    vector<int> nsl(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> v;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                v.push_back(-1);
            else
                v.push_back(st.top());
            st.push(i);
        }
        return v;
    }
    
    vector<int> nsr(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> v;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                v.push_back(heights.size());
            else
                v.push_back(st.top());
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    int mah(vector<int> &heights)
    {
        vector<int> NSL = nsl(heights); 
        vector<int> NSR = nsr(heights);
        vector<int> width;
        for(int i=0;i<NSL.size();i++)
        {
            width.push_back(NSR[i]-NSL[i]-1);
        }
        int mx=0;
        for(int i=0;i<heights.size();i++)
        {
            mx = max(mx,heights[i]*width[i]);
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        int m = matrix.size(),n=matrix[0].size();
        vector<int> heights(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            ans = max(ans,mah(heights));
        }
        return ans;
    }
};