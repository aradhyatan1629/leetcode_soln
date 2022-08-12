class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=0;
        int n = s.size();
        unordered_set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
        j=n-1;
        while(i<j)
        {
            if(v.find(s[i])!=v.end() and v.find(s[j])!=v.end())
            {
                swap(s[i],s[j]);
                i++;
                j--;
                continue;
            }
            else if(v.find(s[i])!=v.end())
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};