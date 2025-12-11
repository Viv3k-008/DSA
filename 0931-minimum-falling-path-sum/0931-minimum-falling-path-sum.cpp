class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() , ans = INT_MAX;
        vector<vector<int>> dp;
        dp.resize(n+1 , vector<int>(m , 0));
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){

                int down = 0 , diagLeft = 1e9 , diagRight = 1e9;
                down = dp[i+1][j];
                if(j-1 >= 0) diagLeft = dp[i+1][j-1];
                if(j+1 < m) diagRight = dp[i+1][j+1];

                dp[i][j] = min({down , diagLeft , diagRight}) + matrix[i][j];
            }
        }

        for(int i = 0 ; i < n ; i++){
            ans = min(ans , dp[0][i]);
        } 

        return ans;
    }
};