class Solution {
public:
    string largestGoodInteger(string num) {
        int mx=0;
        string ans;
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i]==num[i+1] and num[i+1]==num[i+2])
            {
                string s;
                s += num[i]; s+=num[i+1]; s+=num[i+2];
                if(stoi(s)>=mx)
                {
                    mx = stoi(s);
                    ans = s;
                }
            }
        }
        return ans;
    }
};