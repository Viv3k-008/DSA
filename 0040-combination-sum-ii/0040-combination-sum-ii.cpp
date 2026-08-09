class Solution {
public:
    vector<vector<int>> ans;
    void fn(int i, int target, vector<int>& candidates, vector<int>& temp){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        if(i >= candidates.size()) return;


        temp.push_back(candidates[i]);
        if(target >= candidates[i]) fn(i+1, target-candidates[i], candidates, temp);
        temp.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) i++;
        fn(i+1, target, candidates, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        fn(0, target, candidates, temp);

        return ans;
    }
};