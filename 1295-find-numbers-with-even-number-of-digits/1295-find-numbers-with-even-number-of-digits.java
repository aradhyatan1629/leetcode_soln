class Solution {
    public boolean countDigits(int x){
        int cnt = 0;
        while(x!=0){
            cnt++;
            x/=10;
        }
        return cnt%2 == 0;
    }
    
    public int findNumbers(int[] nums) {
        int ans = 0;
        for(int i=0;i<nums.length;i++){
            if(countDigits(nums[i]))
                ans++;
        }
        return ans;
    }
}