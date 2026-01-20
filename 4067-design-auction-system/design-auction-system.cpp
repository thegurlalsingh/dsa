class AuctionSystem {
public:
    unordered_map<int, set<pair<int,int>>> overall;
    unordered_map<long long, int> userBid; // (itemId,userId)->bid

    long long key(int itemId, int userId) {
        return ((long long)itemId << 32) | userId;
    }

    void addBid(int userId, int itemId, int bidAmount) {
        long long k = key(itemId, userId);

        // if user already bid on this item, remove old bid
        if(userBid.count(k)) {
            int old = userBid[k];
            overall[itemId].erase({old, userId});
        }

        overall[itemId].insert({bidAmount, userId});
        userBid[k] = bidAmount;
    }

    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount); // same behavior
    }

    void removeBid(int userId, int itemId) {
        long long k = key(itemId, userId);
        if(userBid.count(k)) {
            int old = userBid[k];
            overall[itemId].erase({old, userId});
            userBid.erase(k);
        }
    }

    int getHighestBidder(int itemId) {
        if(overall[itemId].empty()) return -1;
        return overall[itemId].rbegin()->second;
    }
};
