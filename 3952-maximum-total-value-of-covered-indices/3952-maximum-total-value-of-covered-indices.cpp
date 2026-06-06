class Solution {
public:
    vector<vector<long long>> dp;
    // long long fn(int i , int n , int taken , vector<int>& nums , string& s){
    //     if(i >= n) return 0;

    //     if(dp[i][taken] != -1) return dp[i][taken];

    //     long long cur = 0 , next = 0 , skip = 0;
    
    //     skip = fn(i+1 , n , 0 , nums , s);

    //     if(!taken && s[i] == '1'){
    //         cur = nums[i] + fn(i+1 , n , 0 , nums , s);
    //     }
        
    //     if(i+1 < n && s[i+1] == '1'){
    //         next = nums[i] + fn(i+1 , n , 1 , nums , s);
    //     }
        
        
        
    //     return dp[i][taken] = max({cur, next, skip});
    // }
    long long maxTotal(vector<int>& nums, string s) {

        int n = s.size();
        
        long long ans =  0;

        dp.resize(n+1 , vector<long long>(2 , 0));

        // ans = fn(0 , n , 0 , nums , s);

        // return ans;

        for(int i = n-1 ; i >= 0 ; i--){
            for(int taken = 0 ; taken <= 1 ; taken++){
                long long cur = 0 , next = 0 , skip = 0;
    
                skip = dp[i+1][0];

                if(!taken && s[i] == '1'){
                    cur = nums[i] + dp[i+1][0];
                }
                
                if(i+1 < n && s[i+1] == '1'){
                    next = nums[i] + dp[i+1][1];
                }
                
                dp[i][taken] = max({cur, next, skip});
            }
        }

        return dp[0][0];
    }
};