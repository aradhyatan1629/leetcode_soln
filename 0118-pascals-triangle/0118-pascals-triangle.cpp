class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=2;i<=numRows;i++)
        {
            vector<int> prevRow = ans.back();
            vector<int> currRow(i);currRow[0]=1,currRow[currRow.size()-1]=1;
            int k=0;
            for(int j=1;j<currRow.size()-1;j++)
            {
                currRow[j] = prevRow[k]+prevRow[k+1];
                k++;
            }
            ans.push_back(currRow);
        }
        return ans;
    }
};