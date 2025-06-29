struct Entry {
    string food;
    int rating;

    bool operator<(const Entry& other) const {
        if (rating != other.rating)
            return rating > other.rating; 
        return food < other.food;        
    }
};

class FoodRatings {
public:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, multiset<Entry>> cuisineToFoods;
    unordered_map<string, multiset<Entry>::iterator> foodToIt;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i], cuisine = cuisines[i];
            int rating = ratings[i];
            foodToCuisine[food] = cuisine;
            auto& foodSet = cuisineToFoods[cuisine];
            auto it = foodSet.insert({food, rating});
            foodToIt[food] = it;
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto& foodSet = cuisineToFoods[cuisine];
        auto it = foodToIt[food];
        foodSet.erase(it);
        auto newIt = foodSet.insert({food, newRating});
        foodToIt[food] = newIt;
    }

    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->food;
    }
};
