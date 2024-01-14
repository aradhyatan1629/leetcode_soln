class Solution {
public:
    unordered_set<int> st;
    void PrimeFactors(int n)
    {
        while(n%2 == 0)
        {
            if(st.find(2)==st.end())
                st.insert(2);
            n=n/2;
        }
        for(int i=3;i<=sqrt(n);i++)
        {
            while(n%i == 0)
            {
                if(st.find(i)==st.end())
                    st.insert(i);
                n=n/i;
            }
        }
        if(n>2)
            st.insert(n);
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            PrimeFactors(nums[i]);
        }
        return st.size();
    }
};