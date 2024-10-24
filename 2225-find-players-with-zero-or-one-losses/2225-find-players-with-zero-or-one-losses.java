class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        TreeMap<Integer, Integer> m = new TreeMap<>();
        
        for (int i = 0; i < matches.length; i++) {
            m.put(matches[i][1], m.getOrDefault(matches[i][1], 0) + 1);
        }
                
        TreeSet<Integer> winners = new TreeSet<>();
        for (int i = 0; i < matches.length; i++) {
            if (!m.containsKey(matches[i][0])) {
                winners.add(matches[i][0]);
            }
        }
        
        List<List<Integer>> ans = new ArrayList<>();
        
        List<Integer> v = new ArrayList<>();
        for (Integer x : winners) {
            v.add(x);
        }
        ans.add(new ArrayList<>(v));  // Add a copy of the list
        
        v.clear();  // Clear the list for the second part
        
        for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
            if (entry.getValue() == 1) {
                v.add(entry.getKey());
            }
        }
        ans.add(new ArrayList<>(v));  // Add a copy of the list
        
        return ans;
    }
}
