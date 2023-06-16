class Solution {
public:
    //Linar search O(n)
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '\0';
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i]>target)
            {
                ans = letters[i];
                break;
            }
        }
        if(ans!='\0')
        {
            return ans;
        }
        return letters[0];
    }
};