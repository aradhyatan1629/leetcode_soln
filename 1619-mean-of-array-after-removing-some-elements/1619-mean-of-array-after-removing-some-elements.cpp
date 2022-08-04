class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int temp = (n*5)/100;
        double sum=0;
        for(int i=temp;i<n-temp;i++)
        {
            sum+=arr[i];
        }
        return sum/(n-temp*2);
    }
};