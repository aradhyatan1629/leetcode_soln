class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int n=needle.size();
        if(needle.size()>haystack.size())
        {
            return -1;
        }
        while(i<=haystack.size()-needle.size())
        {
            if(haystack.substr(i,n)==needle)
            {
                return i;
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};