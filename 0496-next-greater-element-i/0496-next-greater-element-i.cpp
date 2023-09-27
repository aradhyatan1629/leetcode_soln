class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                v.push_back(-1);
            }
            else if(!st.empty() and st.top()>nums2[i])
            {
                v.push_back(st.top());
            }
            else if(!st.empty() and st.top()<=nums2[i])
            {
                while(!st.empty() and st.top()<=nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(st.top());
                }
            }
            st.push(nums2[i]);
        }
        reverse(v.begin(),v.end());
        unordered_map<int,int> m;
        for(int i=0;i<v.size();i++)
        {
            m[nums2[i]] = v[i];
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};