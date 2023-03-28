class StockSpanner {
    stack<pair<int,int>> st;
    int index=-1;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res=0;
        index++;
        
        if(st.size()==0)
        {
            res=index+1;
        }
        else if(st.size()>0 and st.top().first>price)
        {
            res = index - st.top().second;
        }
        else if(st.size()>0 and st.top().first<=price)
        {
            while(st.size()>0 and st.top().first<=price)
            {
                st.pop();
            }
            if(st.size()==0)
            {
                res = index+1;
            }
            else
            {
                res = index - st.top().second;
            }
        }
        st.push({price,index});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */