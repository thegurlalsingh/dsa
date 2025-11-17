class Solution {
    bool solve(unordered_set<string>& supply, vector<string>& ing){
        for(string& x : ing){
            if(supply.find(x) == supply.end())
                return false;
        }
        return true;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_set<string> supply(supplies.begin(), supplies.end());

        int n = recipes.size();
        vector<bool> made(n, false);

        bool changed = true;

        while(changed){
            changed = false;
            for(int i = 0; i < n; i++){
                if(!made[i] && solve(supply, ingredients[i])){
                    made[i] = true;
                    supply.insert(recipes[i]);
                    res.push_back(recipes[i]);
                    changed = true;
                }
            }
        }

        return res;
    }
};
