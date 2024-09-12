class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size(), n = mat[0].size();
        
        bool dir = true;  // true = up-right, false = down-left
        int row = 0, col = 0;

        while (ans.size() < m * n) {
            ans.push_back(mat[row][col]);
            
            if (dir) {  // Moving upwards
                if (col == n - 1) {  // Hit the right boundary
                    row++;
                    dir = false;
                } else if (row == 0) {  // Hit the top boundary
                    col++;
                    dir = false;
                } else {
                    row--;
                    col++;
                }
            } else {  // Moving downwards
                if (row == m - 1) {  // Hit the bottom boundary
                    col++;
                    dir = true;
                } else if (col == 0) {  // Hit the left boundary
                    row++;
                    dir = true;
                } else {
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};