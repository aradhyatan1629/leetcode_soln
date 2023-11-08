class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,string>> pq;
        if(a!=0){pq.push({a,"a"});}
        if(b!=0){pq.push({b,"b"});}
        if(c!=0){pq.push({c,"c"});}
        
        
        string ans;
        
        while(pq.size()>1) 
        {
            pair<int,string> top1 = pq.top();pq.pop();
            pair<int,string> top2 = pq.top();pq.pop();
           
            if(top1.first>=2)
            {
                ans+=top1.second;
                ans+=top1.second;
                top1.first-=2;
            }
            else
            {
                ans+=top1.second;
                top1.first-=1;
            }
            if(top2.first>=2 and top2.first>=top1.first)
            {
                ans+=top2.second;
                ans+=top2.second;
                top2.first-=2;
            }
            else
            {
                ans+=top2.second;
                top2.first-=1;
            }
            if(top1.first>0){pq.push(top1);}
            if(top2.first>0){pq.push(top2);}
        }
        if(pq.empty())
        {
            return ans;
        }
        if(pq.top().first>=2)
        {
            ans+=pq.top().second;
            ans+=pq.top().second;
        }
        else
        {
            ans+=pq.top().second;
        }
        return ans;
    }
};







/*

aabaa




*/








