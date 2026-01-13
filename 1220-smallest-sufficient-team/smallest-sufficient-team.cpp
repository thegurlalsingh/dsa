class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        int fullMask = (1 << n) - 1;

        // Map each skill to a bit index
        unordered_map<string, int> skillIndex;
        for (int i = 0; i < n; i++) skillIndex[req_skills[i]] = i;

        // Convert each person's skills to a bitmask
        vector<int> personMask(people.size(), 0);
        for (int i = 0; i < people.size(); i++)
            for (auto& skill : people[i])
                if (skillIndex.count(skill))
                    personMask[i] |= (1 << skillIndex[skill]);

        unordered_map<int, vector<int>> memo; // mask -> smallest team

        // Call the helper function starting with mask 0 (no skills covered)
        return dfs(0, fullMask, personMask, memo);
    }

private:
    vector<int> dfs(int mask, int fullMask, vector<int>& personMask, unordered_map<int, vector<int>>& memo) {
        if (mask == fullMask) return {};           // all skills covered
        if (memo.count(mask)) return memo[mask];   // already computed

        vector<int> bestTeam;

        for (int i = 0; i < personMask.size(); i++) {
            int newMask = mask | personMask[i];
            if (newMask == mask) continue;        // this person adds nothing new

            vector<int> team = dfs(newMask, fullMask, personMask, memo);
            team.push_back(i);                     // include this person

            if (bestTeam.empty() || team.size() < bestTeam.size()) {
                bestTeam = team;
            }
        }

        memo[mask] = bestTeam;                     // memoize result
        return bestTeam;
    }
};
