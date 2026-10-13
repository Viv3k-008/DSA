class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;

        for(int &i : nums) if(i < 0) i *= -1;

        sort(nums.begin(), nums.end());

        int i = 0 , j = n-1;
        while(i <= j){
            ans += nums[j]*nums[j];
            j--;

            if(i > j) break;
            ans -= nums[i]*nums[i];
            i++;
        }

        return ans;
    }
};