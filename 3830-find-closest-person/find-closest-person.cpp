class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dis1 = abs(z - x);
        int dis2 = abs(z - y);
        if(dis1 > dis2){
            return 2;
        }
        else if(dis2 > dis1){
            return 1;
        }
        return 0;
    }
};