class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)
        {
            arr[0]=1;
        }
        for(int i=0;i<arr.size()-1;i++)
        {
            if(abs(arr[i]-arr[i+1])>1)
            {
                arr[i+1]=arr[i]+1;
            }
        }
        return arr[arr.size()-1];
    }
};

// 1 1 2 2 2 
// 1 2 2 2 1

// 1 100 1000
// 1 2 1000
// 1 2 3

// 6 12 3 54 2 7 9 1
// 1 2 3 6 7 9 12 54
// 1 2 3 4 5 6 7 8