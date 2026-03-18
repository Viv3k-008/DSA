class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();

        vector<vector<int>> dp(n , vector<int>(m));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(i == 0){
                    if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                    else{
                        dp[i][j] = dp[i][j-1]+grid[i][j];
                    }
                    continue;
                }
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                    continue;
                }

                dp[i][j] = grid[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(dp[i][j] <= k){
                    ans++;
                }
            }
        }

        return ans;
    }
};