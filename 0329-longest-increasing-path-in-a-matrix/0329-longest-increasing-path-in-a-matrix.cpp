class Solution {
public:
    int di[4] = {-1 , 1 , 0 , 0};
    int dj[4] = {0 , 0 , -1 , 1};
    int fn(int i , int j , int n , int m , vector<vector<int>>& matrix , vector<vector<int>>& dp){
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 1;
        for(int k = 0 ; k < 4 ; k++){
            int newi = i+di[k];
            int newj = j+dj[k];

            if(newi < 0 || newi >= n || newj < 0 || newj >= m || matrix[i][j] >= matrix[newi][newj]){
                continue;
            }

            int cur = 1 + fn(newi , newj , n , m , matrix , dp);

            dp[i][j] = max(dp[i][j] , cur);
        }

        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();

        vector<vector<int>> dp(n , vector<int>(m , -1));

        int ans = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int temp = fn(i , j , n , m , matrix , dp);
                ans = max(ans , temp);
            }
        }

        return ans;
    }
};