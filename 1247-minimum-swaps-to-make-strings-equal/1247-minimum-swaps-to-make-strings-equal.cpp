class Solution {
public:
    int minimumSwap(string s1, string s2) {
        unordered_map<string,int> m;
        int x1=0,y1=0,x2=0,y2=0;
        for(int i=0;i<s1.size();i++)
        {
            (s1[i]=='x')?x1++:y1++;
            (s2[i]=='x')?x2++:y2++;
        }
        if(abs(x1-x2)%2!=0 or abs(y1-y2)%2!=0)
            return -1;
        
        int swaps=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i] and s1[i]=='x' and s2[i]=='y')m["xy"]++;
            if(s1[i]!=s2[i] and s1[i]=='y' and s2[i]=='x')m["yx"]++;
        }
        int ans=0;
        ans += m["xy"]/2;m["xy"]=m["xy"]%2;
        ans += m["yx"]/2;m["yx"]=m["yx"]%2;
        if(m["xy"]!=m["yx"])return -1;
        ans += 2*m["xy"];
        return ans;
    }
};


/*

diff of x and y in both strings should not be odd

*/