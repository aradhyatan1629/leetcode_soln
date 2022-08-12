class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int n=num.size();
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1] and num[i+1]==num[i+2])
            {
                string temp;
                temp.push_back(num[i]);
                temp.push_back(num[i+1]);
                temp.push_back(num[i+2]);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};