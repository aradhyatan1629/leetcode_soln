class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(auto x:sentence)
        {
            s.insert(x);
        }
        if(s.size()==26)
        {
            return 1;
        }
        return false;
    }
};