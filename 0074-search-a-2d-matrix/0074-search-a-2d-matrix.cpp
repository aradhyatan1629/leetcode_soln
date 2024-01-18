class Solution {
public:
    bool binarySearch(vector<int> &v,int target)
    {
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(v[mid]==target)
                return true;
            else if(v[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int i=0,j=n-1;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]<=target and matrix[i][n-1]>=target)
            {
                return binarySearch(matrix[i],target);
            }
        }
        return false;
    }
};

// O(m + logn) , we will check if the target lies in the current row is yes then we will apply binary search only on that row.