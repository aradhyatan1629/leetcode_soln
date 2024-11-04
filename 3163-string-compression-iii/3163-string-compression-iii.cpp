class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int len = 1;
        
        for(int i=0;i<word.size()-1;i++){
            if(len<9 && word[i] == word[i+1]){
                len++;
            }
            else{
                comp += to_string(len) + word[i];
                len = 1;
            }
        }
        comp += to_string(len) + word[word.size()-1];
        return comp;
    }
};