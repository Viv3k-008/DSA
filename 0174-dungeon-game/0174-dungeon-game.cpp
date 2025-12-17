class Solution {
public:
    int n , m;
    int fn(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp){
        if(i >= n || j >= m){
            return 1e9;
        }
        if(i == n-1 && j == m-1){
            if(grid[i][j] <= 0){
                return abs(grid[i][j])+1;
            }
            else return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int down = fn(i+1 , j , grid , dp);
        int right = fn(i , j+1 , grid , dp);

        int req = min(down , right);
        if(grid[i][j] >= req){
            return dp[i][j] = 1;
        }
        return dp[i][j] = req - grid[i][j];
    }
    int calculateMinimumHP(vector<vector<int>>& grid) {
        n = grid.size() , m = grid[0].size();
        // vector<vector<int>> dp(n+1 , vector<int>(m+1 , 1e9));
        vector<int> cur(m+1 , 1e9) , next(m+1 , 1e9);

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j >= 0 ; j--){
                if(i == n-1 && j == m-1){
                    if(grid[i][j] <= 0){
                        cur[j] = abs(grid[i][j])+1;
                    }
                    else cur[j] = 1;
                    continue;
                }

                int down = next[j];
                int right = cur[j+1];

                int req = min(down,right);

                if(grid[i][j] >= req){
                    cur[j] = 1;
                }
                else cur[j] = req-grid[i][j];
            }
            next = cur;
        }

        return next[0];
    }
};