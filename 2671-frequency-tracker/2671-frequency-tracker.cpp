class FrequencyTracker {
public:
    
    unordered_map<int,int> m;
    unordered_map<int,int> m1;
    
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(m[number]==1)
        {
            if(m1[1]>0)
            {
                m1[1]--;
            }
            m1[m[number]+1]++;
            m[number]++;
        }
        else
        {
            if(m1[m[number]]>0)
            {
                m1[m[number]]--;
            }
            m1[m[number]+1]++;
            m[number]++;
        }
    }
    
    void deleteOne(int number) {
        if(m[number]>0)
        {
            if(m1[m[number]]>0)
            {
                m1[m[number]]--;
            }
            m1[m[number]-1]++;
            m[number]--;
        }
    }
    
    bool hasFrequency(int frequency) {
        if(m1[frequency]>0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */