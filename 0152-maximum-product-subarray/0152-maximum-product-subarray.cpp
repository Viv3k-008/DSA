class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prefMul = 1 , suffMul = 1 , ans = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            if(prefMul == 0) prefMul = 1;
            if(suffMul == 0) suffMul = 1;
            
            prefMul *= nums[i];
            suffMul *= nums[n-i-1];

            ans = max({ans , prefMul , suffMul});
        }

        return ans;
    }
};