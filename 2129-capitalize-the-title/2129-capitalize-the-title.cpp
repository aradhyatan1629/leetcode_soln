class Solution {
public:
    string capitalizeTitle(string title) {
        int n=title.size();
        int i=0,j=0;
        while(j<n)
        {
            if(title[j]==' ')
            {
                if(j-i>2)
                {
                    title[i] = toupper(title[i]);
                    transform(title.begin()+i+1,title.end(),title.begin()+i+1,::tolower);
                }
                if(j-i==1 || j-i==2)
                {
                    title[i] = tolower(title[i]);
                    title[i+1] = tolower(title[i+1]);
                }
                i=j+1;
                j=i+1;
            }
            else
            {
                j++;
            }
        }
        if(j-i>2)
        {
            title[i] = toupper(title[i]);
            transform(title.begin()+i+1,title.end(),title.begin()+i+1,::tolower);
        }
         if(j-i==1 || j-i==2)
        {
            title[i] = tolower(title[i]);
            title[i+1] = tolower(title[i+1]);
        }
        return title;
    }
};