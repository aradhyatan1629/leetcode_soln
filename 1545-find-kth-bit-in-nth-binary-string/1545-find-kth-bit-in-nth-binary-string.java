class Solution {
    
    public StringBuilder invert(StringBuilder prev){
        for(int i=0;i<prev.length();i++){
            if(prev.charAt(i) == '0')
                prev.setCharAt(i,'1');
            else
                prev.setCharAt(i,'0');
        }
        prev.reverse();
        return prev;
    }
    
    public char findKthBit(int n, int k) {
        if(n == 1)
            return '0';
        
        StringBuilder prev = new StringBuilder("0");
        StringBuilder curr = null;
        int i = n;
        
        while(i>1){
            curr = new StringBuilder();
            curr.append(prev);
            curr.append('1');
            curr.append(invert(prev));
            prev = curr;  
            i--;
        }
        
        return curr.charAt(k-1);
    }
}