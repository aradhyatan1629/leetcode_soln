class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        long long sum = 0;
        int mxNeg = INT_MIN;
        int mnPos = INT_MAX;
        int cnt = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0)
                    cnt++;
                if(matrix[i][j] < 0 && matrix[i][j] > mxNeg)
                    mxNeg = matrix[i][j];
                if(matrix[i][j] > 0 && matrix[i][j] < mnPos)
                    mnPos = matrix[i][j];
            }
        }
        
        bool flag = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            return sum;
        
        if(cnt%2 == 0)
            return sum;
        
        int cntp=0;
        int cntn=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == mnPos)
                    cntp++;
                if(matrix[i][j] == mxNeg)
                    cntn++;
            }
        }
        
        sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == mnPos && cntp>1){
                    sum += abs(matrix[i][j]);
                    cntp--;
                }
                else if(matrix[i][j] == mxNeg && cntn>1){
                    sum += abs(matrix[i][j]);
                    cntn--;
                }
                else if(matrix[i][j] != mnPos && matrix[i][j] != mxNeg)
                    sum += abs(matrix[i][j]);
            }
        }
        
        if(abs(mnPos) < abs(mxNeg))
            return sum + abs(mxNeg) - mnPos;
        
        long long ans = sum;
        if(mxNeg != INT_MIN)
            ans += mxNeg;
        if(mnPos != INT_MAX)
            ans += mnPos;
        return ans;
        
    }
};






















