class Solution {
public:
    long long minimumSteps(string s) {
        int low = 0;
        int high = s.size()-1;
        
        long long ans = 0;
        while(low <= high){
            if(s[low] == '1' && s[high] == '0'){
                swap(s[low],s[high]);
                ans += (high-low);
                low++,high--;
            }
            else if(s[low] == '0'){
                low++;
            }
            else if(s[high] == '1'){
                high--;
            }
        }
        return ans;
    }
};