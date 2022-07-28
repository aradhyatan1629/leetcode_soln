class Solution {
public:
    int minTimeToType(string word) {
        int ans=0;
        char point='a';
        for(auto ch:word)
        {
            ans+=min(abs(ch-point),26-abs(point-ch));
            point=ch;
        }
        ans+=word.size();
        return ans;
    }
};