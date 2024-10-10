class Solution {
    public int maxWidthRamp(int[] nums) {
        Stack<Integer> st = new Stack<>();
        
        for(int i=0;i<nums.length;i++){
            if(st.isEmpty() || nums[i] <= nums[st.peek()]){
                st.push(i);
            }
        }
        int mx = 0;
        for(int j=nums.length-1;j>=0;j--){
            while(!st.isEmpty() && nums[st.peek()] <= nums[j]){
                mx = Math.max(mx,j-st.peek());
                st.pop();
            }
        }
        return mx;
    }
}