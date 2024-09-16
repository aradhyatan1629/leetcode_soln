class Solution {
    public int maximumWealth(int[][] accounts) {
        int m = accounts.length;
        int n = accounts[0].length;
        
        int mx = 0;
        for(int i=0;i<m;i++){
            int ans = 0;
            for(int j=0;j<n;j++){
                ans += accounts[i][j];
            }
            mx = Math.max(mx,ans);
        }
        return mx;
    }
}