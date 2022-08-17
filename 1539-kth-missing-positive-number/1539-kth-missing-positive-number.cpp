class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v;
        for(int i=1;i<=1000+k;i++)
        {
            if(find(arr.begin(),arr.end(),i)==arr.end())
            {
                v.push_back(i);
            }
        }
        return v[k-1];
    }
};