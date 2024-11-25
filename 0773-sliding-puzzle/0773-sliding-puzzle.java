class Solution {
    public int slidingPuzzle(int[][] board) {
        int r = board.length;
        int c = board[0].length;

        StringBuilder source = new StringBuilder();
        String target = "123450";

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                source.append(board[i][j]);
            }
        }

        HashMap<Integer, List<Integer>> m = new HashMap<>();
        m.put(0, Arrays.asList(1, 3));
        m.put(1, Arrays.asList(0, 2, 4));
        m.put(2, Arrays.asList(1, 5));
        m.put(3, Arrays.asList(0, 4));
        m.put(4, Arrays.asList(1, 3, 5));
        m.put(5, Arrays.asList(2, 4));

        HashMap<String, Integer> vis = new HashMap<>();
        Queue<Pair<String, Integer>> q = new LinkedList<>();

        vis.put(source.toString(), 1);
        q.offer(new Pair<>(source.toString(), 0));

        int ans = Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            String s = q.peek().getKey();
            int lvl = q.peek().getValue();
            q.poll();

            if (s.equals(target)) {
                ans = Math.min(ans, lvl);
            }

            int ind = -1;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    ind = i;
                    break;
                }
            }

            for (int x : m.get(ind)) {
                StringBuilder temp = new StringBuilder(s);
                char ch = temp.charAt(x);
                temp.setCharAt(x, '0');
                temp.setCharAt(ind, ch);

                if (!vis.containsKey(temp.toString())) {
                    vis.put(temp.toString(), 1);
                    q.offer(new Pair<>(temp.toString(), lvl + 1));
                }
            }
        }

        return (ans == Integer.MAX_VALUE) ? -1 : ans;
    }
}
