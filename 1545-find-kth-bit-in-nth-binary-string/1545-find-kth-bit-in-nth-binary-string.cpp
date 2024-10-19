class Solution {
public:
    string invert(string &prev){
        for(int i=0;i<prev.size();i++){
            if(prev[i] == '0')
                prev[i] = '1';
            else
                prev[i] = '0';
        }
        reverse(prev.begin(),prev.end());
        return prev;
    }
    
    char findKthBit(int n, int k) {
        if(n == 1)
            return '0';
        
        string prev = "0";
        string curr  = "";
        int i = n;
        
        while(i>1){
            curr = prev + "1" + invert(prev);
            prev = curr;
            i--;
        }
        return curr[k-1];
    }
};

