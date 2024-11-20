class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length();
        HashMap<Character,Integer> m = new HashMap<>();
        
        for(int i=0;i<n;i++){
            m.put(s.charAt(i),m.getOrDefault(s.charAt(i),0)+1);
        }
        
        if (m.getOrDefault('a', 0) < k || m.getOrDefault('b', 0) < k || m.getOrDefault('c', 0) < k) {
            return -1;
        }
        
        int i = 0;int j = 0;
        int mxLen = 0;
        
        while(j<n){
            m.put(s.charAt(j),m.get(s.charAt(j))-1);
            if(m.get(s.charAt(j)) >= k){
                mxLen = Math.max(mxLen,j-i+1);
                j++;
            }
            else{
                while(m.get(s.charAt(j)) < k){
                    m.put(s.charAt(i),m.get(s.charAt(i))+1);
                    i++;
                }
                j++;
            }
        }
        return n - mxLen;
    }
}