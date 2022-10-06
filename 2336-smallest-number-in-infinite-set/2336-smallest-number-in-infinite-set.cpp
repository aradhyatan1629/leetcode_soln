class SmallestInfiniteSet {
public:
    unordered_map<int,int> m;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {
            m[i]=1;
        }
    }
    
    int popSmallest() {
        int mn=INT_MAX;
        for(auto x:m)
        {
            mn=min(mn,x.first);
        }
        m.erase(mn);
        return mn;
    }
    
    void addBack(int num) {
        if(m[num]==0)
        {
            m[num]=1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */