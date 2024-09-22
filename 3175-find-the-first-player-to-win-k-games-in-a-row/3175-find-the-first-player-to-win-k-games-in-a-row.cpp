class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int mxInd = 0;
        int mx = 0;
        
        for (int i = 0; i < n; i++) {
            if (skills[i] > mx) {
                mxInd = i;
                mx = skills[i];
            }
        }
        
        if (k >= n)
            return mxInd;
        
        unordered_map<int, int> m;  // {index, wins}
        deque<int> dq;
        
        for (int i = 0; i < skills.size(); i++)
            dq.push_back(i);
        
        while (true) {
            int ind1 = dq.front(); dq.pop_front(); 
            int ind2 = dq.front(); dq.pop_front(); 
            
            if (skills[ind1] > skills[ind2]) {
                m[ind1]++;
                dq.push_front(ind1); 
                dq.push_back(ind2);  
                if (m[ind1] == k) return ind1; 
            } else {
                m[ind2]++;
                dq.push_front(ind2); 
                dq.push_back(ind1);  
                if (m[ind2] == k) return ind2; 
            }
        }
        return -1;
    }
};
