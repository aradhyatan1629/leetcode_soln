class Solution {
    public int[] arrayRankTransform(int[] arr) {
        TreeMap<Integer,Integer> m = new TreeMap<>();
        for(int i=0;i<arr.length;i++){
            m.put(arr[i],-1);
        }
        int r = 1;
        for(Map.Entry<Integer,Integer> mp : m.entrySet()){
            m.put(mp.getKey(),r);
            r++;
        }
        
        for(int i=0;i<arr.length;i++){
            arr[i] = m.get(arr[i]);
        }
        
        return arr;
    }
}