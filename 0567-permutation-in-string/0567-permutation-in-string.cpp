class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //Sorting and using sliding window
        int i=0,j=0,n=s2.size();
        sort(s1.begin(),s1.end());
        int k=s1.size();
        string t;
        while(j<n)
        {
            t+=s2[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                string x=t;
                sort(x.begin(),x.end());
                if(s1==x)
                {
                    return true;
                }
                t.erase(t.begin());
                i++;
                j++;
            }
        }
        return false;
    }
};