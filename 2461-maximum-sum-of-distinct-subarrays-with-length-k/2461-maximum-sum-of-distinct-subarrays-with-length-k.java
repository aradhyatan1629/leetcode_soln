class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> m = new HashMap<>();
        int n = nums.length;
        int i = 0;
        int j = 0;
        
        long ans = 0;
        long sum = 0;
        
        while(j<n){
            sum += nums[j];
            m.put(nums[j],m.getOrDefault(nums[j],0)+1);
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(m.size() == k){
                    ans = Math.max(ans,sum);
                }
                sum -= nums[i];
                m.put(nums[i],m.getOrDefault(nums[i],1)-1);
                if(m.get(nums[i]) == 0)
                    m.remove(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
}