class Solution {
public:
    bool isCircularSentence(string sentence) {
        char last;
        int n = sentence.size();
        
        for(int i=0;i<n-1;i++){
            if(sentence[i] == ' ' && (sentence[i-1] != sentence[i+1]))
                return false;
        }
        
        if(sentence[n-1] != sentence[0])
            return false;
        
        return true;
        
    }
};