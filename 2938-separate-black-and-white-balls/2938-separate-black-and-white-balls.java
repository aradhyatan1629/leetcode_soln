class Solution {
    public long minimumSteps(String s) {
        int low = 0;
        int high = s.length()-1;
        
        long ans = 0L;
        while(low <= high){
            if(s.charAt(low) == '1' && s.charAt(high) == '0'){
                ans += (high-low);
                low++;
                high--;
            }
            else if(s.charAt(low) == '0'){
                low++;
            }
            else if(s.charAt(high) == '1'){
                high--;
            }
        }
        return ans;
    }
}