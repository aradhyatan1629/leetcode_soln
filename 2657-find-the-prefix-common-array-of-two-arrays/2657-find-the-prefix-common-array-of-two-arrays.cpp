class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> c;
        unordered_set<int> st;
        int i=0,j=0;
        
        
        for(int j=0;j<B.size();j++)
        {
            st.insert(B[j]);
            int cnt=0;
            for(int i=0;i<=j;i++)
            {
                if(st.find(A[i])!=st.end())
                {
                    cnt++;
                }
            }
            c.push_back(cnt);
        }
        return c;
    }
};