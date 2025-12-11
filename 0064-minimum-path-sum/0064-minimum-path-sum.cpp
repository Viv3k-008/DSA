class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<int>> dp;
        dp.resize(n+1 , vector<int>(m+1 , 1e9));
        dp[n-1][m-1] = grid[n-1][m-1];

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                
                if(i == n-1 && j == m-1) continue;

                int mini = min(dp[i+1][j] , dp[i][j+1]);
                dp[i][j] = mini + grid[i][j];

            }
        }

        return dp[0][0];
    }
};