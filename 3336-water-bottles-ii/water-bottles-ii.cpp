class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrunk = 0;
        int emptyBottles = 0;
        bottlesDrunk += numBottles;
        emptyBottles += numBottles;
        numBottles = 0;
        while(numExchange <= emptyBottles){
            emptyBottles -= numExchange;
            emptyBottles++;
            bottlesDrunk++;
            numExchange++;
        }
        return bottlesDrunk;
    }
};