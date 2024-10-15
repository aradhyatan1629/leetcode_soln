class Solution {
public:
    long long minimumSteps(string s) {
        priority_queue<int> pq;
        long long ans = 0;
        
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '0'){
                pq.push(i);
            }
            else if(s[i] == '1'){
                if(!pq.empty()){
                    ans += pq.top() - i;
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        return ans;
    }
};