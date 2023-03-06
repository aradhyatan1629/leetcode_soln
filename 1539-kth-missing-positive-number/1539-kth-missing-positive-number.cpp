class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1;
        unordered_set<int> st(arr.begin(),arr.end());
        while(k!=0)
        {
            if(st.find(i)==st.end())
            {
                k--;
            }
            if(k==0)
            {
                break;
            }
            i++;
        }
        return i;
    }
};