class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int i=0,mx=INT_MIN,j=0;
        vector<int> v;
        for(i=0;i<arr.size()-1;i++)
        {
            mx=INT_MIN;
            for(j=i+1;j<arr.size();j++)
            {
                if(arr[j]>mx)
                {
                    mx=arr[j];
                }
            }
            v.push_back(mx);
        }
        v.push_back(-1);
        return v;
    }
};