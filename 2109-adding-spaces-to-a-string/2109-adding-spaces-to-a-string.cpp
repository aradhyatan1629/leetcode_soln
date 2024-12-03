class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string ans = "";
        
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(j<m && i == spaces[j]){
                ans += " ";
                j++;
            }
            ans += s[i];
        }
        return ans;
    }
};