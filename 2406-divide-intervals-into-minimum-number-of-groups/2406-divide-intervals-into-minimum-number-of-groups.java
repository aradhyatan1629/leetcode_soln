class Solution {
    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->(a[0]-b[0]));
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for(int i=0;i<intervals.length;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(!pq.isEmpty() && pq.peek() < start){
                pq.poll();
            }
            pq.offer(end);
        }
        return pq.size();
    }
}