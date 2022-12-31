class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0,n=haystack.size();
        int k=needle.size();
        string temp;
        if(needle.size()>haystack.size())
        {
            return -1;
        }
        while(j<n)
        {
            temp+=haystack[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(temp==needle)
                {
                    return i;
                }
                temp.erase(temp.begin());
                i++;
                j++;
            }
        }
        return -1;
    }
};