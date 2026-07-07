class MedianFinder {
public:
multiset<int> ms;
multiset<int>::iterator mid;
    MedianFinder() {

    }
    
    void addNum(int num) {
        ms.insert(num);
        if(ms.size() == 1){
            mid = ms.begin();
        }
        else{
            if(ms.size() % 2 == 0){
                if(num < *mid){
                    mid--;
                }
            }
            else{
                if(num >= *mid){
                    mid++;
                }
            }
        }

    }
    
    double findMedian() {
        if(ms.size() % 2 == 0){
            int a = *mid;
            int b = *next(mid);
            return (a + b) / 2.0;
        }
        return *mid/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */