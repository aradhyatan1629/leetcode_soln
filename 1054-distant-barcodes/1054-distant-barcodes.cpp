class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size()<=2)
            return barcodes;
        
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> m;
        
        for(int i=0;i<barcodes.size();i++)
            m[barcodes[i]]++;
        
        for(auto x:m)
            pq.push({x.second,x.first});
        
        while(pq.size()>1)
        {
            auto top1 = pq.top();pq.pop();
            auto top2 = pq.top();pq.pop();
            
            if(ans.size()>0 and ans.back()==top1.second)
            {
                ans.push_back(top2.second);
                ans.push_back(top1.second);
                top1.first--,top2.first--;
                if(top1.first>0)
                    pq.push(top1);
                if(top2.first>0)
                    pq.push(top2);
            }
            else
            {
                ans.push_back(top1.second);
                ans.push_back(top2.second);
                top1.first--,top2.first--;
                if(top1.first>0)
                    pq.push(top1);
                if(top2.first>0)
                    pq.push(top2);
            }
        }
        if(!pq.empty())
        {
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};

/*


(3,1) (3,2)

1 2 1 2 1 2

(4,1) (2,2) (2,3)

1 2

(3,1) (2,3) (1,2)

1 2 1 3

(2,1) (1,2) (1,3)

1 2 1 3 1 3

(1,3) (1,1)

1 2 1 3 1 3 1 3


[1,1,2]
(2,1) (1,2)

1 2





*/