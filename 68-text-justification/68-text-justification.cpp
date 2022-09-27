class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0;
        while(i<words.size())
        {
            int wordcount=words[i].size();
            int j=i+1;
            
            int candidate=0;
            while(j<words.size() and wordcount+candidate+words[j].size()+1<=maxWidth)
            {
                wordcount+=words[j].size();
                candidate++;
                j++;
            }
            int vacancy=maxWidth-wordcount;
            
            int atleast=candidate==0?0:vacancy/candidate;
            int extra=candidate==0?0:vacancy%candidate;
            if(j==words.size())
            {
                atleast=1;
                extra=0;
            }
            string s;
            for(int k=i;k<j;k++)
            {
                s+=words[k];
                if(k==j-1)
                {
                    break;
                }
                for(int e=0;e<atleast;e++)
                {
                    s+=" ";
                    // extra--;
                }
                if(extra>0)
                {
                    s+=" ";
                    extra--;
                }
            }
            while(s.size()<maxWidth)
            {
                s+=" ";
            }
            ans.push_back(s);
            i=j;
        }
        return ans;
    }
};