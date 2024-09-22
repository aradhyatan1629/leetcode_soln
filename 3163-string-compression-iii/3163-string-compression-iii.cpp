class Solution {
public:
    string compressedString(string word) {
        int c = 1;
        int n = word.size();
        string ans;
        
        for(int i=0;i<n-1;i++){
            if(c<9 && word[i]==word[i+1]){
                c++;
            }
            else{
                if(word[i] == word[i+1])
                    ans += to_string(9);
                else
                    ans += to_string(c);
                ans += word[i];
                c = 1;
            }
            // else if(word[i] == word[i+1]){
            //     ans += to_string(9);
            //     ans += word[i];
            //     c = 1;
            // }
            // else{
            //     ans += to_string(c);
            //     ans += word[i];
            //     c = 1;
            // }
        }
        ans += to_string(c);
        ans += word[n-1];
        return ans;
    }
};