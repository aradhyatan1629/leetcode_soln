class Solution {
    public String compressedString(String word) {
        StringBuilder ans = new StringBuilder();
        int n = word.length();
        int len = 1;
        
        for(int i=0;i<n-1;i++){
            if(len<9 && word.charAt(i) == word.charAt(i+1)){
                len++;
            }
            else{
                ans.append(len);
                ans.append(word.charAt(i));
                len = 1;
            }
        }
        ans.append(len);
        ans.append(word.charAt(n-1));
        return ans.toString();
    }
}