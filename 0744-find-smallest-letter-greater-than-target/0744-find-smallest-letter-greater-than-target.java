class Solution {
    public int search(char[] letters,char x){
        int low = 0;
        int high = letters.length-1;
        int ind = 0;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(letters[mid] <= x){
                low = mid+1;
            }
            else{
                ind = mid;
                high = mid-1;
            }
        }
        return ind;
    }
    
    public char nextGreatestLetter(char[] letters, char target) {
        int ans = search(letters,target);
        return letters[ans];
    }
}