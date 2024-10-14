class Solution {
    public long maxKelements(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y)->(Integer.compare(y,x)));
        for(int i=0;i<nums.length;i++){
            pq.offer(nums[i]);
        }
        long ans = 0L;
        while(k-- > 0){
            ans += pq.peek();
            int x = (int) Math.ceil(pq.peek() / 3.0);
            pq.poll();
            pq.offer(x);
        }
        return ans;
    }
}