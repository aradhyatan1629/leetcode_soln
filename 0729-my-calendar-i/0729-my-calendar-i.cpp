class MyCalendar {
public:
    vector<pair<int,int>> intervals;
    MyCalendar() {
    }
    
    bool check(int a,int b){
        for(int i=0;i<intervals.size();i++){
            int s = intervals[i].first;
            int e = intervals[i].second;
            if(a<e && s<b)
                return true; // this is overlap
        }
        return false;
    }
    
    bool book(int start, int end) {
        if(check(start,end))      // there is overlap
            return false;
        intervals.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */