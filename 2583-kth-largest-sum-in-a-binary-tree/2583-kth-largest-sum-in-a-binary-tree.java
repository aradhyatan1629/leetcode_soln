/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public void bfs(TreeNode root,ArrayList<Long> v){
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        
        while(!q.isEmpty()){
            int sz = q.size();
            long sum = 0;
            for(int i=0;i<sz;i++){
                TreeNode node = q.peek();
                q.poll();
                sum += node.val;
                if(node.left != null)
                    q.offer(node.left);
                if(node.right != null)
                    q.offer(node.right);
            }
            v.add(sum);
        }
    }
    
    public long kthLargestLevelSum(TreeNode root, int k) {
        ArrayList<Long> v = new ArrayList<>();
        bfs(root,v);
        if(k > v.size())
            return -1;
        
        Collections.sort(v,(a,b)->b.compareTo(a)); // descending order sort
        return v.get(k-1);
    }
}