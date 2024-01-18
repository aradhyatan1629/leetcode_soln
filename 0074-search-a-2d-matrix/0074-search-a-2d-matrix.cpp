class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int low=0,high=(m*n)-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col] > target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};

// O(log(m*n)), we are treating the whole 2d array as a single 1d array, due to the nature of the question the 1d array will be sorted. We get corresponding matrix values for each index and check with target.
