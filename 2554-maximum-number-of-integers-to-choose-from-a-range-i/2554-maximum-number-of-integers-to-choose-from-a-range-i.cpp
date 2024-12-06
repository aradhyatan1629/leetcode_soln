class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> s(banned.begin(),banned.end());
        
        int cnt = 0;
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(sum+i > maxSum)
                break;
            if(s.find(i) == s.end()){
                sum += i;
                cnt++;
            }
        }
        return cnt;
    }
};