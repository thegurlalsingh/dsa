class MedianFinder {
    multiset<int> ms;
    multiset<int>::iterator mid;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ms.insert(num);
        if(ms.size() == 1){
            mid = ms.begin();
        }
        else{
            if(num < *mid){
                if(ms.size() % 2 == 0){
                    mid--;
                }
            }
            else{
                if(ms.size() % 2 == 1){
                    mid++;
                }
            }
        }
    }
    
    double findMedian() {
        if(ms.size() % 2 == 0){
            return (*mid + *(next(mid)))/2.0;
        }
        else{
            return (double)*mid;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */