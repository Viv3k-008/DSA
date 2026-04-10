class Solution {
public:
    int mod = 1e9+7;
    int xorAfterQueries(vector<int>& num, vector<vector<int>>& queries) {
        
        int n = queries.size() , m = num.size();
        vector<long long> nums(num
        .begin() , num.end());

        for(int i = 0 ; i < n ; i++){
            int li = queries[i][0];
            int ri = queries[i][1];
            int ki = queries[i][2];
            int vi = queries[i][3];

            for(int idx = li ; idx <= min(ri , m) ; ){
                nums[idx] = (long long)(nums[idx] * vi) % mod;
                idx += ki;
            }
        }

        long long xr = 0;

        for(long long i : nums){
            xr ^= i;
        }

        return xr;
    }
};