class Solution {
private:
    bool canMakeRecipe(vector<string>& ingredients, unordered_map<string, int>& supply) {
        for (auto& ing : ingredients) {
            if (supply.find(ing) == supply.end()) {
                return false;
            }
        }
        return true;
    }
    
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_map<string, int> supply;
        
        for (auto& s : supplies) {
            supply[s] = 1;
        }
        
        int n = recipes.size();
        vector<bool> done(n, false); 
        bool progress = true;
        
        while (progress) {
            progress = false;
            
            for (int i = 0; i < n; i++) {
                if (!done[i] && canMakeRecipe(ingredients[i], supply)) {
                    res.push_back(recipes[i]);
                    supply[recipes[i]] = 1;  
                    done[i] = true;
                    progress = true; 
                }
            }
        }
        
        return res;
    }
};
