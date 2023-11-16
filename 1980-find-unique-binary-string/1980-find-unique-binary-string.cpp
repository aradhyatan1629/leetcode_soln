class Solution {
public:
    
    string generate(string curr,int n,unordered_set<string> &s)
    {
        if(curr.size() == n)
        {
            if(s.find(curr)==s.end())
                return curr;
            return "";
        }
        string t = generate(curr+"0",n,s);
        if(t.size()>0){return t;}
        return generate(curr+"1",n,s);
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s;
        int n=nums.size();
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        
        return generate("",n,s);
    }
};