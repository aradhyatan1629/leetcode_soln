class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<j)
        {
            if(people[i]+people[j]<=limit)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                cnt++;
                j--;
            }
        }
        if(i==j)
        {
            cnt++;
        }
        return cnt;
    }
};
// 1 2 2 3