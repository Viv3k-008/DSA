class Solution {
public:
    vector<vector<int>> ans;
    void fn(int i , vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j = i ; j < nums.size() ; j++){
            swap(nums[i] , nums[j]);
            fn(i+1 , nums);
            swap(nums[i] , nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        fn(0 , nums);

        return ans;
    }
};