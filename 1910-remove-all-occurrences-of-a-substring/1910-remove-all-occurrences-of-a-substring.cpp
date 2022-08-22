class Solution {
public:
    string removeOccurrences(string s, string part) {
        int k=part.size();
        int i=0,j=0;
        int n=s.size();
        string word;
        while(j<n)
        {
            word+=s[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(word==part)
                {
                    // cout<<"word"<<word<<endl;
                    s.erase(s.begin()+i,s.begin()+j+1);
                    // cout<<"s"<<s;
                    i=0;
                    j=0;
                    word.clear();
                }
                else
                {
                    word.erase(word.begin());
                    i++;
                    j++;
                }
            }
        }
        return s;
    }
};