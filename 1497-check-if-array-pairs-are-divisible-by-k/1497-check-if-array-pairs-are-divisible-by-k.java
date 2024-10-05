class Solution {
    public boolean canArrange(int[] arr, int k) {
        HashMap<Integer,Integer> m = new HashMap<>();
        
        for(int i=0;i<arr.length;i++){
            int rem = (arr[i]%k + k)%k;
            m.put(rem,m.getOrDefault(rem,0)+1);
        }
        
        if(m.getOrDefault(0, 0) % 2 != 0) {
            return false;
        }
        
        for (int i = 1; i <= k / 2; i++) {
            if (!m.getOrDefault(i, 0).equals(m.getOrDefault(k - i, 0))) {
                return false;
            }
        }
        return true;
    }
}