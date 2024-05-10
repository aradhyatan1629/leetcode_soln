class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<double> temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double d = (double)(arr[i])/(double)(arr[j]);
                temp.push_back(d);
            }
        }
        sort(temp.begin(),temp.end());
        double ans = temp[k-1];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double d = (double)(arr[i])/(double)(arr[j]);
                if(d == ans)
                    return {arr[i],arr[j]};
            }
        }
        

        return {};
    }
};