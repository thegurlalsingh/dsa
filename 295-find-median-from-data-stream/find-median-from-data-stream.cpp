class MedianFinder {
public:
        multiset<int> mt;
        multiset<int>::iterator it;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(mt.empty()){
            mt.insert(num);
            it = mt.begin();
        }
        else{
            mt.insert(num);
            int sz = mt.size() - 1;
            if(num < *it && sz % 2 != 0){
                it--;
            }
            if(num >= *it && sz % 2 == 0){
                it++;
            }
        }
    }
    
    double findMedian() {
        if(mt.size() % 2 != 0){
            return (double)(*it);
        }
        return (*it + *next(it)) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */