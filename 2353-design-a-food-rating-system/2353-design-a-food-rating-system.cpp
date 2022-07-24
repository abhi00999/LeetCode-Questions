class FoodRatings {
public:
    map<string, set<pair<int,string>>> m;
    map<string,string> m1;
    map<string,int> rate;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        m.clear();
        m1.clear();
        rate.clear();
        int n=foods.size();
        
        for(int i=0;i<n;i++){
            m[cuisines[i]].insert({-ratings[i], foods[i]});
            m1[foods[i]]=cuisines[i];
            rate[foods[i]]=-ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cui= m1[food];
        int rating= rate[food];
        
        m[cui].erase({rating, food});
        m[cui].insert({-newRating, food});
        rate[food]=-newRating;
    }
    
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */