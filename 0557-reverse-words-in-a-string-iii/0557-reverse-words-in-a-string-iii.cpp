class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        int k;
        bool flag=false;
        while(j<s.size())
        {
            if(s[j]!=' ')
            {
                j++;
            }
            else
            {
                flag=true;
                k=j;
                j--;
                while(i<j)
                {
                    swap(s[i++],s[j--]);
                }
                i=k+1,j=k+1;
            }
        }
        if(!flag)
        {
            reverse(s.begin(),s.end());
            return s;
        }
        k++;
        j=s.size()-1;
        while(k<j)
        {
            swap(s[k++],s[j--]);
        }
        return s;
    }
};