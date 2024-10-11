class Solution {
    public int smallestChair(int[][] times, int targetFriend) { 
        int target = times[targetFriend][0];
        Arrays.sort(times,(a,b)->(a[0]-b[0]));
        int ind = -1;
        
        for(int i=0;i<times.length;i++){
            if(times[i][0] == target){
                ind = i;
                break;
            }
        }
        
        PriorityQueue<Pair<Integer,Integer>> pq = new PriorityQueue<>((a,b)->(a.getKey()-b.getKey())); // {departTime,seatN}
        PriorityQueue<Integer> emptySeats = new PriorityQueue<>();
        int currSeat = 0;
        
        for(int i=0;i<ind;i++){
            int newArrive = times[i][0];
            while(!pq.isEmpty() && pq.peek().getKey() <= newArrive){
                emptySeats.offer(pq.peek().getValue());
                pq.poll();
            }
            if(emptySeats.isEmpty()){
                pq.offer(new Pair<Integer,Integer>(times[i][1],currSeat));
                currSeat++;
            }
            else{
                pq.offer(new Pair<Integer,Integer>(times[i][1],emptySeats.peek()));
                emptySeats.poll();
            }
        }
        
        while(!pq.isEmpty() && pq.peek().getKey() <= target){
            emptySeats.offer(pq.peek().getValue());
            pq.poll();
        }
        
        if(!emptySeats.isEmpty())
            return emptySeats.peek();
        
        return currSeat;
    }
}