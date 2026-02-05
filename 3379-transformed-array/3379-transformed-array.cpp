class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n , 0);

        for(int i = 0; i < n; i++){
            int newi = (((i + nums[i]) % n) + n)%n;

            ans[i] = nums[newi];
        }

        return ans;
    }
};