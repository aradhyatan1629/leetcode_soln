class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_set<int> s;
        for(auto x:candy)
        {
            s.insert(x);
        }
        int n = candy.size()/2;
        if(s.size()==n)
        {
            return n;
        }
        if(s.size()>n)
        {
            return n;
        }
        return s.size();
    }
};