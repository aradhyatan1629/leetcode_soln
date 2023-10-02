class Solution {
public:
    
    vector<int> NSL(vector<int> &heights)
    {
        vector<int> v;
        stack<pair<int,int>> st;  //{height,index}
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
        vector<int> v;
        stack<pair<int,int>> st;  //{height,index}
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
    
    int MAH(vector<int> &heights)  //Function to find maximum area of histogram
    {
        vector<int> nsl = NSL(heights);
        vector<int> nsr = NSR(heights);
        
        vector<int> width;
        for(int i=0;i<nsl.size();i++)
        {
            width.push_back(nsr[i]-nsl[i]-1);
        }
        
        int mx=0;
        for(int i=0;i<heights.size();i++)
        {
            mx = max(mx,heights[i]*width[i]);
        }
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int> heights(n,0);
        int mxArea=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]++;
                }
                else
                {
                    heights[j]=0;
                }
            }
            mxArea = max(mxArea,MAH(heights));
        }
        return mxArea;
    }
};

/*convert the 2d array into 1d array and find max area in histogram
 4 1 3 3 2
*/