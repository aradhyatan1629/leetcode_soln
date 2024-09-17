class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m1,m2;
        string word;
        for(int i=0;i<s1.size();i++){
            if(s1[i] == ' '){
                m1[word]++;
                word = "";
            }
            else{
                word += s1[i];
            }
        }
        m1[word]++;
        word = "";
        for(int i=0;i<s2.size();i++){
            if(s2[i] == ' '){
                m2[word]++;
                word = "";
            }
            else{
                word += s2[i];
            }
        }
        m2[word]++;
        
        vector<string> ans;
        for(auto x:m1){
            if(x.second == 1 && m2.find(x.first) == m2.end()){
                ans.push_back(x.first);
            }
        }
        for(auto x:m2){
            if(x.second == 1 && m1.find(x.first) == m1.end()){
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};