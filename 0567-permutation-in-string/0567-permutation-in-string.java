class Solution {
    public boolean check(HashMap<Character,Integer> m1,HashMap<Character,Integer> m2)
    {
        if(m1.size() != m2.size())
            return false;
        
        for(Map.Entry<Character,Integer> mp : m1.entrySet()){
            char k = mp.getKey();
            int v = mp.getValue();
            if(!m2.containsKey(k) || !m1.get(k).equals(m2.get(k)))
                return false;
        }
        return true;
    }
    
    public boolean checkInclusion(String s1, String s2) {
        HashMap<Character,Integer> m1 = new HashMap<>();
        HashMap<Character,Integer> m2 = new HashMap<>();
        
        for(int i=0;i<s1.length();i++){
            char ch = s1.charAt(i);
            m1.put(ch,m1.getOrDefault(ch,0)+1);
        }
        
        int i=0,j=0,n=s2.length();
        int k = s1.length();
        
        while(j<n){
            char ch = s2.charAt(j);
            m2.put(ch,m2.getOrDefault(ch,0)+1);
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(check(m1,m2))
                    return true;
                m2.put(s2.charAt(i),m2.get(s2.charAt(i))-1);
                if(m2.get(s2.charAt(i)) == 0){
                    m2.remove(s2.charAt(i));
                }
                i++;
                j++;
            }
        }
        return false;
    }
}