class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder t = new StringBuilder();
        
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch>=65 && ch<=90)
                t.append((char)(ch+32));
            else if(ch>=97 && ch<=122)
                t.append(ch);
            else if(ch>=48 && ch<=57)
                t.append(ch);
        }
        
        StringBuilder t1 = new StringBuilder(t);
        t.reverse();
      
        return t.toString().equals(t1.toString());
        
    }
}