class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        string temp;
        for(int i=0;i<n;i++)
        {
            temp += to_string((s[i]-'a')+1);
        }
        while(k--)
        {
            int sum = 0;
            for(int i=0;i<temp.size();i++)
                sum += temp[i]-'0';
            temp = to_string(sum);
        }
        
        return stoi(temp);
        
    }
};