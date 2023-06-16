class Solution {
public:
    //Binary Search O(nlogn)
    
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        int ans = 0;
        
        for(int i=0;i<m;i++)
        {
            int low=0,high=n-1;
            int count = 0;
            
            while(low<=high)
            {
                int mid = low + (high-low)/2;
                if(grid[i][mid]<0)
                {
                    count = grid[i].size()-mid;
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            ans+=count;
        }
        return ans;
    }
};


/*


1 1 -1 -2

1 1 1 1

-2 -2 -2 -2

1 2 -3 -3 -3 -3

*/