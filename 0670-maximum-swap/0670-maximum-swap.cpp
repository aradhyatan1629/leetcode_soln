class Solution {
public:
    int maximumSwap(int num) {
        vector<int> lastIndex(10,-1);
        // vector<int> freq(10,0);
        
        string s = to_string(num);
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(lastIndex[s[i]-'0'] == -1){
                lastIndex[s[i]-'0'] = i;
            }
            // freq[s[i]-'0']++;
        }
        
        int x = num;
        priority_queue<int> pq;
        while(x != 0){
            pq.push(x%10);
            x /= 10;
        }
      
        for(int i=0;i<n;i++){
            if(pq.top() > s[i] - '0'){
                swap(s[i],s[lastIndex[pq.top()]]);
                break;
            }
            pq.pop();
        }
        
        return stoi(s);
    }
};




















