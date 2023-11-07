class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0)
        {
            return {};
        }
        long long sum=0;
        long long element=2;
        unordered_set<long long> st;
        while(true)
        {
            sum += element;
            // cout<<sum<<endl;
            if(finalSum >= sum)
            {
                st.insert(element);
                element+=2;
            }
            else
            {
                st.insert(element);
                break;
            }
        }
        // cout<<"sz "<<st.size()<<endl;
        // cout<<sum;
        if(sum>finalSum)
        {
            int x = sum-finalSum;
            st.erase(x);
        }
        vector<long long> ans(st.begin(),st.end());
        return ans;
    }
};