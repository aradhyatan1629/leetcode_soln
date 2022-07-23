class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0,n=colors.size();
        int j=n-1;
        while(colors[0]==colors[j])
        {
            j--;
        }
        while(colors[n-1]==colors[i])
        {
            i++;
        }
        return max(n-1-i,j);
    }
};