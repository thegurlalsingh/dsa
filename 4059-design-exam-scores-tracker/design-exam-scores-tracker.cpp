class ExamTracker {
public:

    vector<pair<long long, long long>> t;
    vector<long long> prefix;
    
    ExamTracker() {
    }
    
    void record(int time, int score) {

        // find insertion position
        int pos = lower_bound(
            t.begin(),
            t.end(),
            make_pair((long long)time, LLONG_MIN)
        ) - t.begin();

        // insert at correct position
        t.insert(t.begin() + pos, {time, score});

        // update prefix
        prefix.insert(prefix.begin() + pos, score);

        // fix prefix from pos onward
        if(pos > 0)
            prefix[pos] += prefix[pos - 1];

        for(int i = pos + 1; i < prefix.size(); i++) {
            prefix[i] = prefix[i - 1] + t[i].second;
        }
    }
    
    long long totalScore(int startTime, int endTime) {
        if(t.empty()) return 0;

        int left = lower_bound(
            t.begin(),
            t.end(),
            make_pair((long long)startTime, LLONG_MIN)
        ) - t.begin();

        int right = upper_bound(
            t.begin(),
            t.end(),
            make_pair((long long)endTime, LLONG_MAX)
        ) - t.begin() - 1;

        if(left >= t.size() || right < 0 || left > right)
            return 0;

        if(left == 0)
            return prefix[right];

        return prefix[right] - prefix[left - 1];
    }
};