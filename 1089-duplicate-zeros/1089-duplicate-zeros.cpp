class Solution {
public:
    void shift(vector<int> &arr,int n,int ind)
    {
        for(int i=n-2;i>ind;i--)
        {
            arr[i+1]=arr[i];
        }
    }
    void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]==0)
            {
                shift(arr,arr.size(),i);
                arr[i+1]=0;
                i++;
            }
        }
    }
};