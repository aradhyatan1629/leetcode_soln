class Solution {
public:
    bool check(unordered_map<char,int> &m1,unordered_map<char,int> &m2){
        if(m1.size() != m2.size())
            return false;
        for(auto x:m1){
            if(m2.find(x.first) == m2.end() || m1[x.first] != m2[x.first])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }
        
        int i=0,j=0,n=s2.size();
        int k = s1.size();
        
        while(j<n){
            m2[s2[j]]++;
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(check(m1,m2))
                    return true;
                m2[s2[i]]--;
                if(m2[s2[i]] == 0)
                    m2.erase(s2[i]);
                i++,j++;
            }
        }
        return false;
    }
};


/*

defd    ed
        

*/