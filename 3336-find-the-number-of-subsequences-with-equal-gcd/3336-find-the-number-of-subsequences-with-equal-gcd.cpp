class Solution {
public:
    int MOD = 1e9+7;
    int findGCD(int a, int b){
        if(b == 0){
            return a;
        }

        return findGCD(b, a%b);
    }
    int fn(int i, int n, int gcd1, int gcd2, vector<int>& nums, vector<vector<vector<int>>>& dp){
        if(i == n){
            if(gcd1 == gcd2 && gcd1 != 0){
                return 1;
            }
            return 0;
        }

        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];

        int temp = gcd1;
        gcd1 = (gcd1 == 0)? nums[i] : findGCD(gcd1,nums[i]);
        int op1 = fn(i+1, n, gcd1, gcd2, nums, dp);
        gcd1 = temp;

        temp = gcd2;
        gcd2 = (gcd2 == 0)? nums[i] : findGCD(gcd2,nums[i]);
        int op2 = fn(i+1, n, gcd1, gcd2, nums, dp);
        gcd2 = temp;

        int skip = fn(i+1, n, gcd1, gcd2, nums, dp);

        return dp[i][gcd1][gcd2] = ((long long)op1+op2+skip)%MOD;

    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(201, vector<int>(201, -1)));

        return fn(0, n, 0, 0, nums, dp);
    }
};