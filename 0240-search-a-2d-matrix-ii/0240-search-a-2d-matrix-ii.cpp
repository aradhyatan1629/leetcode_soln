class Solution {
public:
    //O(nlogm)
    bool bs(int low,int high,vector<int> v,int target)
    {
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(v[mid] == target)
            {
                return true;
            }
            else if(v[mid]<target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(target>=matrix[i][0] and target<=matrix[i][n-1])
            {
                if(bs(0,n-1,matrix[i],target))
                {
                    return true;
                }
            }
        }
        return false;
    }
};