class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string t1,t2;
        for(auto x:word1)
            t1+=x;
        for(auto x:word2)
            t2+=x;
        
        if(t1==t2)
            return true;
        return false;
    }
};