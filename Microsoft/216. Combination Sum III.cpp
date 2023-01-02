class Solution {
public:

    void combos(int k, int n, set<int>& comb, set<vector<int>>& res, int i){
        // base case
        if(k == 0){

           if(n==0){
                vector<int> combination;
                for(auto x: comb) combination.push_back(x);
                res.insert(combination);
            }

            return;
        }

        if(n<0 or i>9) return;

        // recursive case
        comb.insert(i);
        combos(k-1, n-i, comb, res, i+1);
        comb.erase(i);

        combos(k, n, comb, res, i+1);

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> comb;
        set<vector<int>> res;
        
        combos(k, n, comb, res, 1);

        vector<vector<int>> ans;

        for(auto x: res){ 
            ans.push_back(x);
        }

        return ans;
    }
};
