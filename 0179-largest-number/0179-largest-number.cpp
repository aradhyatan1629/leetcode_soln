class Solution {
public:
    static bool cmp(int a,int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        if(s1 + s2 > s2 + s2)   // 3,41 -> 341<413,return false 41must be befor 3
            return true;
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        if(nums[0]=='0')
            return "0";
        string ans = "";
        for(int i=0;i<nums.size();i++){
            ans += to_string(nums[i]);
        }
        bool flag = false;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                flag = true;
                break;
            }
        }
        if(flag)
            return ans;
        return "0";
    }
};