typedef pair<long long, long long> P; //{move per unit, element}

class Solution {
    struct cmp {
        bool operator()(const P& a, const P& b) {
            return a.first > b.first;   
        }
    };

public:
    long long minMoves(vector<int>& balance) {
        int negIdx = -1; long long negElem = 0; int n = balance.size();
        for(int i = 0; i < balance.size(); i++){
            if(balance[i] < 0){
                negIdx = i; negElem = balance[i];
            }
        }
        long long moves = 0;
        priority_queue<P, vector<P>, cmp> pq; 
        for(int i = 0; i < balance.size(); i++){
            if(i != negIdx && balance[i] > 0){
                int idxStraight = abs(negIdx - i);
                int idxCircular = n - abs(negIdx - i);
                pq.push({min(idxStraight, idxCircular), balance[i]});
            }
        }
        while(!pq.empty() && negElem < 0){
            auto t = pq.top(); pq.pop();
            moves += t.first * min(t.second , abs(negElem));
            negElem += min(t.second , abs(negElem));
        }
        if(negElem >= 0){
            return moves;
        }
        return -1;
    }
};