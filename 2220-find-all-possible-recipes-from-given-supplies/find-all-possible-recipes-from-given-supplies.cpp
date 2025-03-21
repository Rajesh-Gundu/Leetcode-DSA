class Solution {
public:
    bool check(string& curRecipe,int i,vector<vector<string>>& ingredients,unordered_set<string>& available,unordered_map<string,int>& recipe,vector<int>& canMake,unordered_set<string>& callStack) {
        if(canMake[i] != -1)
            return canMake[i];
        if(callStack.count(curRecipe))
            return canMake[i] = 0;
        callStack.insert(curRecipe);
        for(auto& ingred : ingredients[i]) {
            if(!available.count(ingred)) {
                if(!recipe.count(ingred)) {
                    return canMake[i] = 0;
                }
                if(!check(ingred,recipe[ingred],ingredients,available,recipe,canMake,callStack)) {
                    return canMake[i] = 0;
                }
            }
        }
        callStack.erase(curRecipe);
        return canMake[i] = 1;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int i = 0;
        int n = recipes.size();
        unordered_map<string,int> recipe;
        for(int i=0;i<n;i++) {
            recipe[recipes[i]] = i;
        }
        unordered_set<string> available(supplies.begin(),supplies.end());
        vector<string> ans;
        vector<int> canMake(n,-1);
        while(i < n) {
            unordered_set<string> callStack;
            check(recipes[i],i,ingredients,available,recipe,canMake,callStack);
            i++;
        }
        for(int i=0;i<n;i++) {
            if(canMake[i] == 1)
                ans.push_back(recipes[i]);
        }
        return ans;
    }
};